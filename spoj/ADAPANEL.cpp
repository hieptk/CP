// https://www.spoj.com/problems/ADAPANEL/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;
const ll mod = 1000000007;

int n, m;
vector<int> adj[nm];
ll f[nm];
int d, num[nm], low[nm];
int nc, comp[nm], cnt[nm], maxc;
int ns, st[nm];

void dfs(int i) {
	low[i] = num[i] = ++d;
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
			cnt[nc]++;
		} while (j != i);
		maxc = max(maxc, cnt[nc]);
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
	}
	for (int i = 0; i < n; ++i) {
		if (!num[i]) {
			ns = 0;
			dfs(i);
		}
	}

	f[0] = 1;
	for (int i = 1; i <= maxc; ++i) {
		int l = (1.0 - sqrt(24 * i + 1) / 6) - 1;
		int r = (1.0 + sqrt(24 * i + 1) / 6) + 1;
		for (int j = l; j <= r; ++j) {
			int k = j * (3 * j - 1) / 2;
			if (k > 0 && k <= i) {
				if (j & 1) {
					f[i] = (f[i] + f[i - k]) % mod;
				} else {
					f[i] = (f[i] - f[i - k] + mod) % mod;
				}
			}
		}
	}

	ll res = 1;
	for (int i = 1; i <= nc; ++i) {
		res = (res * f[cnt[i]]) % mod;
	}
	printf("%lld\n", res);
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}

