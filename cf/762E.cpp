// https://codeforces.com/contest/762/problem/E
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
const int mm = 10000 + 12;

struct rec {
	int x, r, f;
};

int n, k;
rec a[nm];
pitem treap[mm];

bool cmp(rec &a, rec &b) {
	return a.r > b.r;
}

int cnt_leq(pitem &t, int x) {
	if (!t) {
		return 0;
	}
	if (t->key == x) {
		return cnt(t->l) + 1;
	} else if (t->key < x) {
		return cnt(t->l) + 1 + cnt_leq(t->r, x);
	} else {
		return cnt_leq(t->l, x);
	}
}

int query(pitem &t, int u, int v) {
	return cnt_leq(t, v) - cnt_leq(t, u - 1);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].x >> a[i].r >> a[i].f;
	}
	sort(a + 1, a + n + 1, cmp);

	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		for (int f = max(a[i].f - k, 1); f <= a[i].f + k; ++f) {
			res += query(treap[f], a[i].x - a[i].r, a[i].x + a[i].r);
		}
		insert(treap[a[i].f], new item(a[i].x, rand()));
	}
	cout << res << "\n";
}

