#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
    (cerr << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 702;

int n, m;
vector<int> adj[nm];
int num[nm], low[nm];
int d;
int par[nm];
int nb;
pair<int, int> b[nm];

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

void solve(int test) {
	printf("Caso #%d\n", test);
	scanf("%d%d", &n, &m);
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
	nb = 0;
	for (int i = 1; i <= n; ++i) {
		if (par[i] != -1) {
			if (low[i] >= num[i]) {
				b[nb++] = {min(i, par[i]), max(i, par[i])};
			}
		}
	}
	if (!nb) {
		printf("Sin bloqueos\n");
		return;
	}
	sort(b, b + nb);
	printf("%d\n", nb);
	for  (int i = 0; i < nb; ++i) {
		printf("%d %d\n", b[i].first, b[i].second);
	}
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

