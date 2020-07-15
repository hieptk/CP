// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=995
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 52;
const int mm = 1002;

int m;
vector<int> adj[nm];
pair<int, int> edge[mm];
bool used[mm];
int nr, res[mm];

void dfs(int i) {
	while (adj[i].size()) {
		int e = adj[i].back();
		adj[i].pop_back();
		if (used[e]) {
			continue;
		}
		used[e] = 1;
		int j = edge[e].fi ^ edge[e].se ^ i;
		dfs(j);
	}
	res[++nr] = i;
}

void solve(int test) {
	cout << "Case #" << test << "\n";
	for (int i = 1; i < nm; ++i) {
		adj[i].clear();
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> edge[i].fi >> edge[i].se;
		adj[edge[i].fi].eb(i);
		adj[edge[i].se].eb(i);
	}
	int s = 0;
	for (int i = 1; i < nm; ++i) {
		if (adj[i].size() % 2) {
			cout << "some beads may be lost\n";
			return;
		}
		if (adj[i].size()) {
			s = i;
		}
	}
	memset(used, 0, sizeof(used));
	nr = 0;
	dfs(s);
	for (int i = 1; i < nm; ++i) {
		if (adj[i].size()) {
			cout << "some beads may be lost\n";
			return;
		}
	}
	for (int i = 1; i <= m; ++i) {
		cout << res[i] << " " << res[i % m + 1] << "\n";
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
		if (i < t) {
			cout << "\n";
		}
	}
}

