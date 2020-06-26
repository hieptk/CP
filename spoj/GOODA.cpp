// https://www.spoj.com/problems/GOODA/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1000002;

int n, m, s, t;
ll a[nm];
vector<int> adj[nm], adj2[nm];
int num[nm], low[nm], d;
int nc, comp[nm];
ll sum[nm];
int ns, st[nm];
ll f[nm];
bool calc[nm];

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
			sum[nc] += a[j];
		} while (j != i);
	}
}

void dp(int i) {
	calc[i] = 1;
	if (i == comp[t]) {
		f[i] = sum[i];
		return;
	}
	ll &res = f[i] = -1;
	for (int j: adj2[i]) {
		if (!calc[j]) {
			dp(j);
		}
		res = max(res, f[j]);
	}
	if (res >= 0) {
		res += sum[i];
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
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
				adj2[comp[i]].eb(comp[j]);
			}
		}
	}
	dp(comp[s]);
	printf("%lld\n", f[comp[s]]);
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}

