// https://www.spoj.com/problems/MEANARR/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

struct item {
    int prior, cnt, val;
    ll key;
    item * l, * r;
    item() { }
    item (ll key, int prior) : key(key), prior(prior), l(NULL), r(NULL), val(1) { }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = t->val + cnt(t->l) + cnt (t->r);
}

void split (pitem t, ll key, pitem & l, pitem & r) {
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

int n;
ll k;
pitem root;

int cnt_lte(pitem t, ll x) {
	if (!t) {
		return 0;
	}
	if (t->key == x) {
		return cnt(t->l) + t->val;
	}
	if (t->key < x) {
		return cnt(t->l) + t->val + cnt_lte(t->r, x);
	}
	return cnt_lte(t->l, x);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	ll s = 0, res = 0;
	insert(root, new item(0, rand()));
	for (int i = 1; i <= n; ++i) {
		ll a;
		cin >> a;
		s += a - k;
		res += cnt_lte(root, s);
		insert(root, new item(s, rand()));
	}
	cout << res << "\n";
}

