// https://www.spoj.com/problems/COUNT1IT/
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

int n, m;
pitem root;

int cnt_lte(pitem &t, int x) {
	if (!t) {
		return 0;
	}
	if (t->key == x) {
		return cnt(t->l) + t->val;
	} else if (t->key < x) {
		return cnt(t->l) + t->val + cnt_lte(t->r, x);
	} else {
		return cnt_lte(t->l, x);
	}
}

int zth(pitem t, int x) {
	if (x <= cnt(t->l)) {
		return zth(t->l, x);
	} else if (x <= cnt(t->l) + t->val) {
		return t->key;
	} else {
		return zth(t->r, x - cnt(t->l) - t->val);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		insert(root, new item(x, rand()));
	}
	for (int i = 1; i <= m; ++i) {
		int t, x;
		cin >> t >> x;
		switch (t) {
		case 1:
			insert(root, new item(x + cnt_lte(root, x), rand()));
			break;
		case 2:
			cout << cnt_lte(root, x) << "\n";
			break;
		default:
			if (x > cnt(root)) {
				cout << "invalid\n";
			} else {
				cout << zth(root, x) << "\n";
			}
		}
	}
}

