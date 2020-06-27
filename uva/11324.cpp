// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2299
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;

int n, m;
vector<int> adj[nm], adj2[nm];
int d, num[nm], low[nm];
int ns, st[nm];
int nc, comp[nm], cnt[nm];
int f[nm];

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
		cnt[++nc] = 0;
		adj2[nc].clear();
		int j;
		do {
			j = st[ns--];
			comp[j] = nc;
			cnt[nc]++;
		} while (j != i);
	}
}

int dp(int i) {
	if (f[i] > 0) {
		return f[i];
	}
	int &res = f[i] = 0;
	for (int j: adj2[i]) {
		res = max(res, dp(j));
	}
	return res += cnt[i];
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		num[i] = comp[i] = 0;
	}
	d = nc = 0;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
	}
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			ns = 0;
			dfs(i);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j: adj[i]) {
			if (comp[i] != comp[j]) {
				adj2[comp[i]].eb(comp[j]);
			}
		}
	}

	memset(f, 0, sizeof(f));
	int res = 0;
	for (int i = 1; i <= nc; ++i) {
		res = max(res, dp(i));
	}
	printf("%d\n", res);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}

