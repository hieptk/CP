// https://www.spoj.com/problems/TWIST/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;


const int nm = 100002;

int n, m, a[nm];
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dist(INT_MIN, INT_MAX);

typedef struct item * pitem;
struct item {
	int prior, value, cnt;
	bool rev;
	pitem l, r;
	explicit item(int value): prior(dist(gen)), value(value), cnt(1), rev(false), l(nullptr), r(nullptr) {}
};

int cnt (pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
	if (it)
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
	if (it && it->rev) {
		it->rev = false;
		swap (it->l, it->r);
		if (it->l)  it->l->rev ^= true;
		if (it->r)  it->r->rev ^= true;
	}
}

void merge (pitem & t, pitem l, pitem r) {
	push (l);
	push (r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge (l->r, l->r, r),  t = l;
	else
		merge (r->l, l, r->l),  t = r;
	upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void( l = r = nullptr );
	push (t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key)
		split (t->l, l, t->l, key, add),  r = t;
	else
		split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
	upd_cnt (t);
}

void output (pitem t) {
	if (!t)  return;
	push (t);
	output (t->l);
	cout << t->value << " ";
	output (t->r);
}

void reverse (pitem t, int l, int r) {
	pitem t1, t2, t3;
	split (t, t1, t2, l);
	split (t2, t2, t3, r-l+1);
	t2->rev ^= true;
	merge (t, t1, t2);
	merge (t, t, t3);
}

void heapify (pitem t) {
	if (!t) return;
	pitem max = t;
	if (t->l != nullptr && t->l->prior > max->prior)
		max = t->l;
	if (t->r != nullptr && t->r->prior > max->prior)
		max = t->r;
	if (max != t) {
		swap (t->prior, max->prior);
		heapify (max);
	}
}

pitem build (int * a, int n) {
	// Construct a treap on values {a[0], a[1], ..., a[n - 1]}
	if (n == 0) return nullptr;
	int mid = n / 2;
	auto t = new item (a[mid]);
	t->l = build (a, mid);
	t->r = build (a + mid + 1, n - mid - 1);
	upd_cnt(t);
	heapify (t);
	return t;
}

pitem root;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1;
	}
	root = build(a, n);
	for (int i = 1; i <= m; ++i) {
		int l, r;
		cin >> l >> r;
		reverse(root, l - 1, r - 1);
	}
	output(root);
}
