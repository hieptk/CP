// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_f
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

struct item {
    int key, prior, cnt, cnt_this;
    ll sum;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL), cnt(1), cnt_this(1), sum(key) { }
    item (int key, int prior, int cnt_this) : key(key), prior(prior), l(NULL), r(NULL), cnt(1), cnt_this(cnt_this), sum(key) { }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

ll sum(pitem t) {
	return t ? t->sum : 0;
}

void upd_cnt (pitem t) {
    if (t) {
        t->cnt = t->cnt_this + cnt(t->l) + cnt (t->r);
        t->sum = (ll) t->key * t->cnt_this + sum(t->l) + sum(t->r);
    }
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
    else if (it->key == t->key) {
    	t->cnt_this += it->cnt_this;
    }
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
        pitem th = t;
        merge (t, t->l, t->r);
        delete th;
    }
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

pitem unite (pitem l, pitem r) {
    if (!l || !r)  return l ? l : r;
    if (l->prior < r->prior)  swap (l, r);
    pitem lt, rt;
    split (r, l->key, lt, rt);
    l->l = unite (l->l, lt);
    l->r = unite (l->r, rt);
    return l;
}

int cnt_leq(pitem t, int x) {
	if (!t) {
		return 0;
	}
	if (t->key == x) {
		return cnt(t->l) + t->cnt_this;
	}
	if (t->key < x) {
		return cnt(t->l) + t->cnt_this + cnt_leq(t->r, x);
	}
	return cnt_leq(t->l, x);
}

ll sum_leq(pitem t, int x) {
	if (!t) {
		return 0;
	}
	if (t->key == x) {
		return sum(t->l) + (ll) t->key * t->cnt_this;
	}
	if (t->key < x) {
		return sum(t->l) + (ll) t->key * t->cnt_this + sum_leq(t->r, x);
	}
	return sum_leq(t->l, x);
}

const int nm = 200002;

int n, m, q, aa[nm], bb[nm];
pitem a, b;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(2512);
	cin >> n >> m >> q;
	for (int i = 1; i <= n; ++i) {
		insert(a, new item(0, rand()));
	}
	for (int i = 1; i <= m; ++i) {
		insert(b, new item(0, rand()));
	}

	ll res = 0;
	for (int i = 1; i <= q; ++i) {
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1) {
			if (y > aa[x]) {
				res += (ll) cnt_leq(b, aa[x]) * (y - aa[x]);
				res += (ll) (cnt_leq(b, y - 1) - cnt_leq(b, aa[x])) * y - (sum_leq(b, y - 1) - sum_leq(b, aa[x]));
			} else if (y < aa[x]) {
				res += (ll) cnt_leq(b, y) * (y - aa[x]);
				res += (sum_leq(b, aa[x] - 1) - sum_leq(b, y)) - (ll) (cnt_leq(b, aa[x] - 1) - cnt_leq(b, y)) * aa[x];
			}
			insert(a, new item(aa[x], rand(), -1));
			aa[x] = y;
			insert(a, new item(y, rand(), 1));
		} else {
			if (y > bb[x]) {
				res += (ll) cnt_leq(a, bb[x]) * (y - bb[x]);
				res += (ll) (cnt_leq(a, y - 1) - cnt_leq(a, bb[x])) * y - (sum_leq(a, y - 1) - sum_leq(a, bb[x]));
			} else if (y < bb[x]) {
				res += (ll) cnt_leq(a, y) * (y - bb[x]);
				res += (sum_leq(a, bb[x] - 1) - sum_leq(a, y)) - (ll) (cnt_leq(a, bb[x] - 1) - cnt_leq(a, y)) * bb[x];
			}
			insert(b, new item(bb[x], rand(), -1));
			bb[x] = y;
			insert(b, new item(y, rand(), 1));
		}
		cout << res << "\n";
	}
}

