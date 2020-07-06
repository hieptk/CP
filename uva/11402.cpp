// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1024002;

int n;
string s;
int tree[4 * nm];
int add[4 * nm]; // 1: set to 0, 2: set to 1, 3: flip

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = s[l - 1] - '0';
		add[id] = 0;
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	tree[id] = tree[c1] + tree[c2];
	add[id] = 0;
}

void push(int l, int m, int r, int id, int c1, int c2) {
	switch (add[id]) {
	case 1:
		tree[c1] = tree[c2] = 0;
		add[c1] = add[c2] = 1;
		add[id] = 0;
		break;
	case 2:
		tree[c1] = m - l + 1;
		tree[c2] = r - m;
		add[c1] = add[c2] = 2;
		add[id] = 0;
		break;
	case 3:
		tree[c1] = m - l + 1 - tree[c1];
		tree[c2] = r - m - tree[c2];
		add[c1] = 3 - add[c1];
		add[c2] = 3 - add[c2];
		add[id] = 0;
		break;
	}
}

void update(int u, int v, int x, int l, int r, int id) {
	if (u == l && v == r) {
		tree[id] = x * (r - l + 1);
		add[id] = x + 1;
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(l, m, r, id, c1, c2);
	if (u <= m) {
		update(u, min(m, v), x, l, m, c1);
	}
	if (v > m) {
		update(max(u, m + 1), v, x, m + 1, r, c2);
	}
	tree[id] = tree[c1] + tree[c2];
}

void flip(int u, int v, int l, int r, int id) {
	if (u == l && v == r) {
		tree[id] = r - l + 1 - tree[id];
		add[id] = 3 - add[id];
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(l, m, r, id, c1, c2);
	if (u <= m) {
		flip(u, min(m, v), l, m, c1);
	}
	if (v > m) {
		flip(max(u, m + 1), v, m + 1, r, c2);
	}
	tree[id] = tree[c1] + tree[c2];
}

int get(int u, int v, int l, int r, int id) {
	if (u == l && v == r) {
		return tree[id];
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(l, m, r, id, c1, c2);
	int res = 0;
	if (u <= m) {
		res += get(u, min(m, v), l, m, c1);
	}
	if (v > m) {
		res += get(max(u, m + 1), v, m + 1, r, c2);
	}
	return res;
}

void solve(int test) {
	cout << "Case " << test << ":\n";
	int m;
	cin >> m;
	s = "";
	for (int i = 1; i <= m; ++i) {
		string tmp;
		int cnt;
		cin >> cnt >> tmp;
		for (int j = 1; j <= cnt; ++j) {
			s += tmp;
		}
	}
	n = s.length();
	build(1, n, 1);
	int q;
	cin >> q;
	int cnt = 0;
	for (int i = 1; i <= q; ++i) {
		char x;
		int u, v;
		cin >> x >> u >> v;
		u++;
		v++;
		switch (x) {
		case 'F':
			update(u, v, 1, 1, n, 1);
			break;
		case 'E':
			update(u, v, 0, 1, n, 1);
			break;
		case 'I':
			flip(u, v, 1, n, 1);
			break;
		default:
			cout << "Q" << ++cnt << ": " << get(u, v, 1, n, 1) << "\n";
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}

