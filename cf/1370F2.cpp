// https://codeforces.com/contest/1370/problem/F2
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;

int n;
vector<int> adj[nm];
int d[nm], maxd[nm];
int par[nm][nm];

void dfs(int i, int p) {
	par[i][d[i]] = i;
	if (p != -1) {
		for (int j = d[p]; j >= 0; --j) {
			par[i][j] = par[p][j];
		}
	}
	maxd[i] = d[i];
	for (int j: adj[i]) {
		if (j != p) {
			d[j] = d[i] + 1;
			dfs(j, i);
			maxd[i] = max(maxd[i], maxd[j]);
		}
	}
}

bool ok(int di, int &u2, int dist, int u) {
	vector<int> tmp;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == di && par[i][d[u]] == u) {
			tmp.eb(i);
		}
	}
	cout << "? " << tmp.size();
	for (int i: tmp) {
		cout << " " << i;
	}
	cout << "\n";
	cout.flush();
	int dist2;
	cin >> u2 >> dist2;
	return dist2 == dist;
}

int find(int u, int dist, int mind, int maxd) {
	int l = mind, r = maxd, v = u;
	int u2;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ok(mid, u2, dist, u)) {
			v = u2;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return v;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].eb(v);
		adj[v].eb(u);
	}
	cout << "? ";
	cout << n << " ";
	for (int i = 1; i <= n; ++i) {
		cout << i << " ";
	}
	cout << "\n";
	cout.flush();
	int lca, dist;
	cin >> lca >> dist;
	d[lca] = 0;
	dfs(lca, -1);
	int r1 = find(lca, dist, d[lca] + (dist + 1) / 2, min(d[lca] + dist, maxd[lca]));
	if (dist == d[r1] - d[lca]) {
		cout << "! " << lca << " " << r1 << "\n";
		string res;
		cin >> res;
		return;
	}
	vector<int> tmp;
	for (int i = 1; i <= n; ++i) {
		if (d[i] + d[r1] - 2 * d[lca] == dist && par[i][d[lca]] == lca && i != par[r1][d[i]]) {
			tmp.eb(i);
		}
	}
	int r2;
	if (tmp.size() > 1) {
		cout << "? " << tmp.size();
		for (int i: tmp) {
			cout << " " << i;
		}
		cout << "\n";
		cout.flush();
		int dist2;
		cin >> r2 >> dist2;
	} else {
		r2 = tmp[0];
	}
	cout << "! " << r1 << " " << r2 << "\n";
	cout.flush();
	string res;
	cin >> res;

}

int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}
