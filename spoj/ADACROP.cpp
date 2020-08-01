// https://www.spoj.com/problems/ADACROP/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

const int nm = 200002;

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



int n, m;
int a[nm];
map<int, pitem> treap;

int query(pitem &t, int u) {
	if (!t) {
		return 0;
	}
	if (u == t->key) {
		return cnt(t->l);
	} else if (u < t->key) {
		return query(t->l, u);
	} else {
		return cnt(t->l) + 1 + query(t->r, u);
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
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		insert(treap[a[i]], new item(i, rand()));
	}

	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		cout << query(treap[v], u) << "\n";
		erase(treap[a[u]], u);
		a[u] = v;
		insert(treap[v], new item(u, rand()));
	}
}

