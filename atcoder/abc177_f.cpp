// https://atcoder.jp/contests/abc177/tasks/abc177_f
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 200002;
const ll inf = 1e9;

struct rec {
	ll min, min2, add;
	int pos;
};

int m, n;
rec tree[4 * nm];
int a[nm], b[nm];

void push(int id, int c1, int c2, int l, int m, int r) {
	if (tree[id].add > 0) {
		tree[c1] = {tree[id].add, tree[id].add, tree[id].add, l};
		tree[c2] = {tree[id].add + m - l + 1, tree[id].add + m - l + 1, tree[id].add + m - l + 1, m + 1};
		tree[id].add = 0;
	}
}

rec combine(rec &a, rec &b) {
	rec res;
	res.min = min(a.min, b.min);
	if (a.min2 - a.pos <= b.min2 - b.pos) {
		res.min2 = a.min2;
		res.pos = a.pos;
	} else {
		res.min2 = b.min2;
		res.pos = b.pos;
	}
	return res;
}

void update(int u, int v, ll x, int l, int r, int id) {
	if (l >= u && r <= v) {
		tree[id] = {x + l - u, x + l - u, x + l - u, l};
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(id, c1, c2, l, m, r);
	if (u <= m) {
		update(u, v, x, l, m, c1);
	}
	if (v > m) {
		update(u, v, x, m + 1, r, c2);
	}
	tree[id] = combine(tree[c1], tree[c2]);
}

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = {0, 0, 0, l};
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	tree[id] = {0, 0, 0, r};
}

rec get_minpos(int u, int l, int r, int id) {
	if (l > u) {
		return {inf, inf, 0, 0};
	}
	if (r <= u) {
		return tree[id];
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(id, c1, c2, l, m, r);
	rec x1 = get_minpos(u, l, m, c1);
	rec x2 = get_minpos(u, m + 1, r, c2);
	rec res = combine(x1, x2);
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i] >> b[i];
	}
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		if (a[i] > 1) {
			rec tmp = get_minpos(a[i] - 1, 1, n, 1);
			update(a[i], b[i], tmp.min2 + a[i] - tmp.pos, 1, n, 1);
		} else {
			update(a[i], b[i], inf, 1, n, 1);
		}
		if (tree[1].min < inf) {
			cout << i + tree[1].min << "\n";
		} else {
			cout << "-1\n";
		}
	}
#ifdef LOCAL
	cout << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}

