// https://codeforces.com/problemset/problem/1234/D
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

string s;
int n, m, tree[4 * nm];

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = 1 << (s[l - 1] - 'a');
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	tree[id] = tree[c1] | tree[c2];
}

void update(int u, char c, int l, int r, int id) {
	if (l == r) {
		tree[id] = 1 << (c - 'a');
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	if (u <= m) {
		update(u, c, l, m, c1);
	} else {
		update(u, c, m + 1, r, c2);
	}
	tree[id] = tree[c1] | tree[c2];
}

int get(int u, int v, int l, int r, int id) {
	if (l >= u && r <= v) {
		return tree[id];
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	int res = 0;
	if (u <= m) {
		res = get(u, v, l, m, c1);
	}
	if (v > m) {
		res |= get(u, v, m + 1, r, c2);
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = s.length();
	build(1, n, 1);
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int u;
			char c;
			cin >> u >> c;
			update(u, c, 1, n, 1);
		} else {
			int u, v;
			cin >> u >> v;
			cout << __builtin_popcount(get(u, v, 1, n, 1)) << "\n";
		}
	}
}

