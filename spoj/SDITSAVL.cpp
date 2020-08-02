// https://www.spoj.com/problems/SDITSAVL/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

struct item {
    int prior, cnt;
    ll key;
    item * l, * r;
    item() { }
    item (ll key, int prior) : key(key), prior(prior), l(NULL), r(NULL) { }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
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
    else if (it->prior > t->prior)
        split (t, it->key, it->l, it->r),  t = it;
    else
        insert (it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}

int n;
pitem root;

int cnt_lte(pitem &t, ll x) {
	if (!t) {
		return -1;
	}
	if (t->key == x) {
		return cnt(t->l) + 1;
	} else if (t->key > x) {
		return cnt_lte(t->l, x);
	} else {
		int tmp = cnt_lte(t->r, x);
		if (tmp == -1) {
			return -1;
		}
		return tmp + cnt(t->l) + 1;
	}
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
		int t;
		ll x;
		cin >> t >> x;
		if (t == 1) {
			insert(root, new item(x, rand()));
		} else {
			int tmp = cnt_lte(root, x);
			if (tmp == -1) {
				cout << "Data tidak ada\n";
			} else {
				cout << tmp << "\n";
			}
		}
	}

}

