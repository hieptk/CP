//https://www.spoj.com/problems/SUBMERGE/
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 10002;

int n, m;
vector<int> adj[nm];
int num[nm], low[nm];
int d;
int par[nm], nchild[nm];

void dfs(int i, int p) {
	num[i] = low[i] = ++d;
	par[i] = p;
	nchild[i] = 0;
	for (int j: adj[i]) {
		if (j != p) {
			if (!num[j]) {
				nchild[i]++;
				dfs(j, i);
				low[i] = min(low[i], low[j]);
			} else {
				low[i] = min(low[i], num[j]);
			}
		}
	}
}

void solve() {
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
	}
	memset(num, 0, sizeof(num));
	d = 0;
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			dfs(i, -1);
		}
	}
	unordered_set<int> cuts;
	for (int i = 1; i <= n; ++i) {
		int u = par[i];
		if (u == -1) {
			if (nchild[i] >= 2) {
				cuts.insert(i);
			}
		} else {
			if (par[u] != -1 && low[i] >= num[u]) {
				cuts.insert(u);
			}
		}
	}
	printf("%d\n", cuts.size());
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (1) {
		scanf("%d%d", &n, &m);
		if (!n && !m) {
			break;
		}
		solve();
	}
}


