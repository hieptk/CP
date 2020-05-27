// https://codeforces.com/gym/100114/problem/J
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 10002;

int n, m;
vector<int> adj2[nm];
int d, num[nm], low[nm], par[nm];
int ncomp, comp[nm];
int dist[nm];
unordered_map<int, int> adj[nm];

void dfs(int i, int p) {
	num[i] = low[i] = ++d;
	par[i] = p;
	for (auto &p: adj[i]) {
		int j = p.first, c = p.second;
		if (c) {
			if (!num[j]) {
				adj[j][i]--;
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
	comp[i] = ncomp;
	for (auto &p: adj[i]) {
		int j = p.first;
		if (!comp[j] && !is_bridge(i, j)) {
			dfs2(j);
		}
	}
}

void dfs3(int i) {
	for (int j: adj2[i]) {
		if (dist[j] > dist[i] + 1) {
			dist[j] = dist[i] + 1;
			dfs3(j);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u][v]++;
		adj[v][u]++;
	}
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			d++;
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			ncomp++;
			dfs2(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (auto &p: adj[i]) {
			int j = p.first;
			if (comp[i] != comp[j]) {
				adj2[comp[i]].eb(comp[j]);
				adj2[comp[j]].eb(comp[i]);
			}
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[1] = 0;
	dfs3(1);
	int u = 1;
	for (int i = 2; i <= ncomp; ++i) {
		if (dist[i] > dist[u]) {
			u = i;
		}
	}
	memset(dist, 0x3f, sizeof(dist));
	dist[u] = 0;
	dfs3(u);
	int v = 1;
	for (int i = 2; i <= ncomp; ++i) {
		if (dist[i] > dist[v]) {
			v = i;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (comp[i] == u) {
			u = i;
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (comp[i] == v) {
			v = i;
			break;
		}
	}
	printf("%d %d\n", u, v);
}


