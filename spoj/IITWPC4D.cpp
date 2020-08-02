// https://www.spoj.com/problems/IITWPC4D/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

struct item {
    int key, prior, cnt;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    upd_cnt(t);
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void erase (pitem & t, int key) {
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

const int nm = 100002;

int n, a[nm], res[nm];

int zth(pitem t, int x) {
	if (x <= cnt(t->l)) {
		return zth(t->l, x);
	} else if (x <= cnt(t->l) + 1) {
		return t->key;
	} else {
		return zth(t->r, x - cnt(t->l) - 1);
	}
}

void solve(int test) {
	cout << "Test : " << test << "\n";
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	pitem root = 0;
	for (int i = 1; i <= n; ++i) {
		insert(root, new item(i, rand()));
	}
	for (int i = n; i >= 1; --i) {
		if (i - a[i] < 1) {
			cout << "-1\n";
			return;
		}
		res[i] = zth(root, i - a[i]);
		erase(root, res[i]);
	}
	for (int i = 1; i < n; ++i) {
		cout << res[i] << " ";
	}
	cout << res[n] << "\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}

