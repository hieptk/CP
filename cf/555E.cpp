// https://codeforces.com/problemset/problem/555/E
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 200002;

int n, m, q;
vector<int> adj2[nm];
int d, num[nm], low[nm];
int comp[nm], ncomps;
int par[nm];
int ppar[nm][20];
int dep[nm];
int b[nm], e[nm], l[nm];
int comp0[nm], ncomps0;
bool checked[nm];
unordered_map<int, int> adj[nm];

void dfs(int i, int p) {
	num[i] = low[i] = ++d;
	par[i] = p;
	comp0[i] = ncomps0;
	for (auto &p: adj[i]) {
		int j = p.first, c = p.second;
		if (c > 0) {
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
	comp[i] = ncomps;
	for (auto &p: adj[i]) {
		int j = p.first;
		if (!comp[j] && !is_bridge(i, j)) {
			dfs2(j);
		}
	}
}

void dfs3(int i) {
	for (int k = 1; dep[i] - (1 << k) >= 1; ++k) {
		ppar[i][k] = ppar[ppar[i][k - 1]][k - 1];
	}
	for (int j: adj2[i]) {
		if (!dep[j]) {
			dep[j] = dep[i] + 1;
			ppar[j][0] = i;
			dfs3(j);
		}
	}
}

int jump_up(int u, int n) {
	for (int i = 0; n; ++i) {
		if ((n >> i) & 1) {
			u = ppar[u][i];
			n &= ~(1 << i);
		}
	}
	return u;
}

int lca(int u, int v) {
	if (dep[u] > dep[v]) {
		u = jump_up(u, dep[u] - dep[v]);
	} else if (dep[v] > dep[u]) {
		v = jump_up(v, dep[v] - dep[u]);
	}
	if (u == v) {
		return u;
	}
	for (int i = log(dep[u] - 1) / log(2) + 1; ppar[u][0] != ppar[v][0]; --i) {
		if (ppar[u][i] != ppar[v][i]) {
			u = ppar[u][i];
			v = ppar[v][i];
		}
	}
	return ppar[u][0];
}

bool dfs4(int i) {
	checked[i] = 1;
	for (int j: adj2[i]) {
		if (!checked[j]) {
			if (!dfs4(j)) {
				return 0;
			}
			b[i] += b[j];
			e[i] += e[j];
			l[i] += l[j];
		}
	}
	return b[i] <= l[i] || e[i] <= l[i];
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u][v]++;
		adj[v][u]++;
	}
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			ncomps0++;
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			ncomps++;
			dfs2(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (auto &p: adj[i]) {
			int j = p.first;
			if (comp[i] != comp[j]) {
				adj2[comp[i]].eb(comp[j]);
			}
		}
	}

	for (int i = 1; i <= ncomps; ++i) {
		if (!dep[i]) {
			dep[i] = 1;
			dfs3(i);
		}
	}

	for (int i = 1; i <= q; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (comp0[u] != comp0[v]) {
			printf("No\n");
			return 0;
		}
		u = comp[u];
		v = comp[v];
		b[u]++;
		e[v]++;
		int x = lca(u, v);
		l[x]++;
	}

	for (int i = 1; i <= ncomps; ++i) {
		if (!checked[i]) {
			if (!dfs4(i)) {
				printf("No\n");
				return 0;
			}
		}
	}

	printf("Yes\n");
}


