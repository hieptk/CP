// https://codeforces.com/contest/515/problem/E
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;
const ll inf = 1e18;

struct node {
	ll smax, lmax, rmax, l, r;
};

int n, m;
ll d[nm], h[nm], pos[nm];
node tree[4 * nm];

node combine(node &l, node &r) {
	if (l.l > l.r) {
		return r;
	}
	if (r.l > r.r) {
		return l;
	}
	node res;
	res.l = l.l;
	res.r = r.r;
	res.smax = max({l.smax, r.smax, l.rmax + r.lmax + r.l - l.r});
	res.lmax = max(l.lmax, r.l - l.l + r.lmax);
	res.rmax = max(r.rmax, r.r - l.r + l.rmax);
	return res;
}

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = {-inf, 2ll * h[l], 2ll * h[l], pos[l], pos[l]};
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	tree[id] = combine(tree[c1], tree[c2]);
}

node get(int u, int v, int l, int r, int id) {
	if (l >= u && r <= v) {
		return tree[id];
	}
	if (l > v || r < u) {
		return {-inf, -inf, -inf, inf, -inf};
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	node L = get(u, v, l, m, c1), R = get(u, v, m + 1, r, c2);
	return combine(L, R);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}
	for (int i = 2; i <= n; ++i) {
		pos[i] = pos[i - 1] + d[i - 1];
	}
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) {
			node res = get(v + 1, u - 1, 1, n, 1);
			cout << res.smax << "\n";
		} else {
			node l = get(v + 1, n, 1, n, 1), r = get(1, u - 1, 1, n, 1);
			r.l += pos[n] + d[n];
			r.r += pos[n] + d[n];
			node res = combine(l, r);
			cout << res.smax << "\n";
		}
	}
}

