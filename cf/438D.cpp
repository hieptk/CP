// https://codeforces.com/contest/438/problem/D
#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int nm = 100002;

struct node {
	ll sum;
	int maxpos;
};

int n, m;
ll a[nm];
node tree[4 * nm];

void merge(node &parent, node &c1, node &c2) {
	parent.sum = c1.sum + c2.sum;
	if (c1.maxpos != -1 && (c2.maxpos == -1 || a[c1.maxpos] >= a[c2.maxpos])) {
		parent.maxpos = c1.maxpos;
	} else {
		parent.maxpos = c2.maxpos;
	}
}

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = {a[l], l};
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	merge(tree[id], tree[c1], tree[c2]);
}

void update(int u, int v, int l, int r, int id) {
	if (l == r) {
		a[l] = v;
		tree[id] = {a[l], l};
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	if (u <= m) {
		update(u, v, l, m, c1);
	} else {
		update(u, v, m + 1, r, c2);
	}
	merge(tree[id], tree[c1], tree[c2]);
}

node query(int u, int v, int l, int r, int id) {
	if (l >= u && r <= v) {
		return tree[id];
	}
	if (l > v || r < u) {
		return {0, -1};
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	node n1 = query(u, v, l, m, c1), n2 = query(u, v, m + 1, r, c2);
	node res;
	merge(res, n1, n2);
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, n, 1);
	for (int i = 1; i <= m; ++i) {
		int type;
		cin >> type;
		switch (type) {
		case 1:
			int l, r;
			cin >> l >> r;
			cout << query(l, r, 1, n, 1).sum << "\n";
			break;
		case 2:
			int x;
			cin >> l >> r >> x;
			do {
				int u = query(l, r, 1, n, 1).maxpos;
				if (a[u] < x) {
					break;
				}
				update(u, a[u] % x, 1, n, 1);
			} while (1);
			break;
		default:
			cin >> l >> x;
			update(l, x, 1, n, 1);
		}
	}
}

