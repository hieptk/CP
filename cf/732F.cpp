// https://codeforces.com/contest/732/problem/F
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 400002;

int n, m;
vector<int> adj[nm], adj2[nm];
pair<int, int> edge[nm];
int d, num[nm], low[nm], par[nm];
int nc, comp[nm], cnt[nm];
int dep[nm];

void dfs(int i, int p) {
	num[i] = low[i] = ++d;
	par[i] = p;
	for (int j: adj[i]) {
		if (j != p) {
			if (!num[j]) {
				dfs(j, i);
				low[i] = min(low[i], low[j]);
			} else {
				low[i] = min(low[i], num[j]);
			}
		}
	}
}

bool is_bridge(int i, int j) {
	if (i == par[j]) {
		return low[j] >= num[j];
	}
	if (j == par[i]) {
		return low[i] >= num[i];
	}
	return 0;
}

void dfs2(int i) {
	comp[i] = nc;
	cnt[nc]++;
	for (int j: adj[i]) {
		if (!comp[j] && !is_bridge(i, j)) {
			dfs2(j);
		}
	}
}

void dfs3(int i) {
	for (int j: adj2[i]) {
		if (!dep[j]) {
			dep[j] = dep[i] + 1;
			dfs3(j);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &edge[i].fi, &edge[i].se);
		adj[edge[i].fi].eb(edge[i].se);
		adj[edge[i].se].eb(edge[i].fi);
	}
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			nc++;
			dfs2(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j: adj[i]) {
			if (comp[i] != comp[j]) {
				adj2[comp[i]].eb(comp[j]);
			}
		}
	}
	int u = 1;
	for (int i = 2; i <= nc; ++i) {
		if (cnt[i] > cnt[u]) {
			u = i;
		}
	}
	dep[u] = 1;
	dfs3(u);
	printf("%d\n", cnt[u]);
	for (int i = 1; i <= m; ++i) {
		int u = comp[edge[i].fi], v = comp[edge[i].se];
		if (dep[u] < dep[v]) {
			printf("%d %d\n", edge[i].se, edge[i].fi);
		} else if (dep[u] > dep[v]){
			printf("%d %d\n", edge[i].fi, edge[i].se);
		} else if (edge[i].fi == par[edge[i].se]){
			printf("%d %d\n", edge[i].fi, edge[i].se);
		} else if (edge[i].se == par[edge[i].fi]) {
			printf("%d %d\n", edge[i].se, edge[i].fi);
		} else if (num[edge[i].fi] < num[edge[i].se]){
			printf("%d %d\n", edge[i].se, edge[i].fi);
		} else {
			printf("%d %d\n", edge[i].fi, edge[i].se);
		}
	}
}

