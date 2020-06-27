// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=862&page=show_problem&problem=4805
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 5002;

int n, m;
bool adj[nm][nm];
int d, num[nm], low[nm];
int ns, st[nm];
int nc, comp[nm];

void dfs(int i) {
	num[i] = low[i] = ++d;
	st[++ns] = i;
	for (int j = 1; j <= n; ++j) {
		if (adj[i][j] && !comp[j]) {
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

void solve() {
	memset(adj, 1, sizeof(adj));
	memset(num, 0, sizeof(num));
	memset(comp, 0, sizeof(comp));
	d = nc = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u][v] = 0;
	}
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			ns = 0;
			dfs(i);
		}
	}
	ll D;
	scanf("%lld", &D);
	printf("%lld\n", D * nc);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	while (scanf("%d%d", &n, &m) == 2) {
		solve();
	}
}

