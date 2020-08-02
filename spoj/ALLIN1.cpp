// https://www.spoj.com/problems/ALLIN1/
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
	if (!t) {
		return;
	}
    if (t->key == key)
        merge (t, t->l, t->r);
    else
        erase (key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

pitem root;

int cnt_lte(pitem &t, int x) {
	if (!t) {
		return -1;
	}
	if (t->key == x) {
		return cnt(t->l) + 1;
	} else if (t->key < x) {
		int tmp = cnt_lte(t->r, x);
		if (tmp == -1) {
			return -1;
		}
		return cnt(t->l) + 1 + tmp;
	} else {
		return cnt_lte(t->l, x);
	}
}

int kth(pitem &t, int k) {
	if (k <= cnt(t->l)) {
		return kth(t->l, k);
	} else if (k == cnt(t->l) + 1) {
		return t->key;
	} else {
		return kth(t->r, k - cnt(t->l) - 1);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	srand(2512);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n;
	do {
		cin >> t >> n;
		switch (t) {
		case 1:
			insert(root, new item(n, rand()));
			break;
		case 2:
			erase(root, n);
			break;
		case 3:
			cout << cnt_lte(root, n) << "\n";
			break;
		case 4:
			if (n < 1 || n > cnt(root)) {
				cout << "-1\n";
			} else {
				cout << kth(root, n) << "\n";
			}
			break;
		default:
			return 0;
		}
	} while (1);

}

