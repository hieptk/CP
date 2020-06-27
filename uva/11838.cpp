// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2938
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 2002;

int n, m;
vector<int> adj[nm];
int d, num[nm], low[nm];
int nc, comp[nm];
int ns, st[nm];

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

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	do {
		scanf("%d%d", &n, &m);
		if (!n && !m) {
			break;
		}
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u].eb(v);
			if (w == 2) {
				adj[v].eb(u);
			}
		}
		d = 0;
		memset(num, 0, sizeof(num));
		nc = 0;
		memset(comp, 0, sizeof(comp));
		for (int i = 1; i <= n; ++i) {
			if (!num[i]) {
				ns = 0;
				dfs(i);
			}
		}
		if (nc == 1) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	} while (1);
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}

