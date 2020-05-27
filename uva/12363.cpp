// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3785
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 10002;

int n, m, q;
vector<int> adj[nm];
int d, num[nm], low[nm];
int ncomps, comp[nm];
int par[nm];

void dfs(int i, int p) {
	low[i] = num[i] = ++d;
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
	comp[i] = ncomps;
	for (int j: adj[i]) {
		if (!comp[j] && is_bridge(i, j)) {
			dfs2(j);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	do {
		scanf("%d%d%d", &n, &m, &q);
		if (!n && !m && !q) {
			break;
		}
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 1; i<= m; ++i) {
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
		ncomps = 0;
		memset(comp, 0, sizeof(comp));
		for (int i = 1; i <= n; ++i) {
			if (!comp[i]) {
				ncomps++;
				dfs2(i);
			}
		}
		for (int i = 1; i <= q; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (comp[u] == comp[v]) {
				printf("Y\n");
			} else {
				printf("N\n");
			}
		}
		printf("-\n");
	} while (1);
}


