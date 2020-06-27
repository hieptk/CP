// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2870
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 10002;

int n, m;
vector<int> adj[nm];
int d, num[nm], low[nm];
int indeg[nm];
int ns, st[nm];
int nc, comp[nm];

void dfs(int i) {
	num[i] = low[i] = ++d;
	st[++ns] = i;
	for (int j: adj[i]) {
		if (!comp[j]) {
			if (!num[j]) {
				dfs(j);
				low[i] = min(low[i], low[j]);
			} else {
				low[i] = min(low[i], num[j]);
			}
		}
	}
	if (low[i] == num[i]) {
		nc++;
		int j;
		do {
			j = st[ns--];
			comp[j] = nc;
		} while (j != i);
	}
}

void solve(int test) {
	printf("Case %d: ", test);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		num[i] = indeg[i] = comp[i] = 0;
	}
	d = nc = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			ns = 0;
			dfs(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j: adj[i]) {
			if (comp[i] != comp[j]) {
				indeg[comp[j]]++;
			}
		}
	}
	int res = 0;
	for (int i = 1; i <= nc; ++i) {
		if (!indeg[i]) {
			res++;
		}
	}

	printf("%d\n", res);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}

