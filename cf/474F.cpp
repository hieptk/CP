// https://codeforces.com/contest/474/problem/F
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

int n, a[nm];
pair<int, int> tree[4 * nm];

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = {a[l], 1};
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	tree[id].fi = __gcd(tree[c1].fi, tree[c2].fi);
	tree[id].se = 0;
	if (tree[id].fi == tree[c1].fi) {
		tree[id].se = tree[c1].se;
	}
	if (tree[id].fi == tree[c2].fi) {
		tree[id].se += tree[c2].se;
	}
}

pair<int, int> get(int u, int v, int l, int r, int id) {
	if (l >= u && r <= v) {
		return tree[id];
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	pair<int, int> r1, r2;
	if (u <= m) {
		r1 = get(u, v, l, m, c1);
	} else {
		r1 = {0, 0};
	}
	if (v > m) {
		r2 = get(u, v, m + 1, r, c2);
	} else {
		r2 = {0, 0};
	}
	pair<int, int> res;
	res.fi = __gcd(r1.fi, r2.fi);
	res.se = 0;
	if (res.fi == r1.fi) {
		res.se = r1.se;
	}
	if (res.fi == r2.fi) {
		res.se += r2.se;
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	build(1, n, 1);
	int m;
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		printf("%d\n", v - u + 1 - get(u, v, 1, n, 1).se);
	}
}

