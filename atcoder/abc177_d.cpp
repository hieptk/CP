// https://atcoder.jp/contests/abc177/tasks/abc177_d
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 200002;

int n, m;
vector<int> adj[nm];
int nc, cnt[nm], comp[nm];

void dfs(int i) {
	cnt[nc]++;
	comp[i] = nc;
	for (int j: adj[i]) {
		if (!comp[j]) {
			dfs(j);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			nc++;
			dfs(i);
			res = max(res, cnt[nc]);
		}
	}
	cout << res << "\n";
}

