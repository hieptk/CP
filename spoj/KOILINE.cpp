// https://www.spoj.com/problems/KOILINE/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

struct item {
    int key, prior, cnt, val;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL), val(1) { }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = t->val + cnt(t->l) + cnt (t->r);
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
    else if (t->key == it->key)
    	t->val += it->val;
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
    if (t->key == key) {
    	if (t->val > 1) {
    		t->val--;
    	} else {
    		merge (t, t->l, t->r);
    	}
    } else
        erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

const int nm = 100002;

int n, a[nm], res[nm];
pitem root;

int kth(pitem t, int k) {
	if (k <= cnt(t->l)) {
		return kth(t->l, k);
	}
	if (k <= cnt(t->l) + t->val) {
		return t->key;
	}
	return kth(t->r, k - cnt(t->l) - t->val);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int h;
		cin >> h;
		insert(root, new item(h, rand()));
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = n; i >= 1; --i) {
		res[i] = kth(root, a[i] + 1);
		erase(root, res[i]);
	}

	for (int i = 1; i <= n; ++i) {
		cout << res[i] << "\n";
	}
}

