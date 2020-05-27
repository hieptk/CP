// https://www.spoj.com/problems/GRAFFDEF/
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 100002;

int n, m;
vector<int> adj[nm];
int d, low[nm], num[nm], par[nm];
int ncomp, comp[nm], cnt[nm];

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
	comp[i] = ncomp;
	cnt[ncomp]++;
	for (int j: adj[i]) {
		if (!comp[j] && !is_bridge(i, j)) {
			dfs2(j);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
	}
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			ncomp++;
			dfs2(i);
		}
	}
	ll res = 0;
	for (int i = 1; i <= ncomp; ++i) {
		res += (ll) cnt[i] * (cnt[i] - 1) / 2;
	}
	printf("%.5lf\n", 1.0 - 1.0 * res / ((ll) n * (n - 1) / 2));
}

