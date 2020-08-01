// https://www.spoj.com/problems/ADAAPHID/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

struct item {
    ll key, val, prior;
    ll sum;
    item * l, * r;
    item() { }
    item (ll key, ll val, ll prior) : key(key), val(val), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

ll sum(pitem t) {
	return t ? t->sum : 0;
}

void updateSum(pitem t) {
	if (t) {
		t->sum = t->val + sum(t->l) + sum(t->r);
	}
}

void split (pitem t, ll key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    updateSum(t);
}

void insert (pitem & t, pitem it) {
    if (!t)
        t = it;
    else if (it->key == t->key)
    	t->val += it->val;
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    updateSum(t);
}

int n;

ll query(pitem &t, ll a) {
	if (!t) {
		return 0;
	}
	if (t->key == a) {
		return sum(t->l) + t->val;
	} else if (t->key > a) {
		return query(t->l, a);
	} else {
		return sum(t->l) + t->val + query(t->r, a);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll L = 0;
	cin >> n;
	pitem root = NULL;
	for (int i = 1; i <= n; ++i) {
		ll a, v;
		cin >> a >> v;
		a ^= L;
		v ^= L;
		insert(root, new item(a, v, rand()));
		L = query(root, a);
		cout << a << " " << L << "\n";
	}
}

