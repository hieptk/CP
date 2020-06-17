// https://codeforces.com/contest/1364/problem/D
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

int n, m, k;
vector<int> adj[nm];
int par[nm];
int f[nm][2];
int nr, res[nm];
int ns, st[nm];
int d[nm], mark[nm];

void dp(int i, int p) {
	f[i][1] = 1;
	f[i][0] = 0;
	par[i] = p;
	for (int j: adj[i]) {
		if (j != p) {
			dp(j, i);
			f[i][1] += f[j][0];
			f[i][0] += max(f[j][0], f[j][1]);
		}
	}
}

bool get_res(int i, int c) {
	if (c) {
		res[++nr] = i;
		if (nr == (k + 1) / 2) {
			return 1;
		}
		for (int j: adj[i]) {
			if (j != par[i]) {
				if (get_res(j, 0)) {
					return 1;
				}
			}
		}
	} else {
		for (int j: adj[i]) {
			if (j != par[i]) {
				int cj;
				if (f[j][0] > f[j][1]) {
					cj = 0;
				} else {
					cj = 1;
				}
				if (get_res(j, cj)) {
					return 1;
				}
			}
		}
	}
	return 0;
}

bool dfs(int i, int p, int di, int maxlen) {
	mark[i] = 1;
	d[i] = di;
	st[++ns] = i;
	for (int j: adj[i]) {
		if (j != p) {
			if (!mark[j]) {
				if (dfs(j, i, di + 1, maxlen)) {
					return 1;
				}
			} else if (mark[j] == 1 && di - d[j] + 1 <= maxlen){
				do {
					res[++nr] = st[ns--];
				} while (res[nr] != j);
				return 1;
			}
		}
	}
	ns--;
	mark[i] = 2;
	return 0;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d%d", &n, &m, &k);
	for (int i= 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
	}
	if (m == n - 1) {
		dp(1, -1);
		for (int i = 1; i <= n; ++i) {
			if (f[i][0] >= (k + 1) / 2) {
				get_res(i, 0);
				break;
			} else if (f[i][1] >= (k + 1) / 2) {
				get_res(i, 1);
				break;
			}
		}
		printf("1\n");
		for (int i = 1; i <= nr; ++i) {
			printf("%d ", res[i]);
		}
		printf("\n");
	} else {
		if (dfs(1, -1, 1, k)) {
			printf("2\n%d\n", nr);
			for (int i = 1; i <= nr; ++i) {
				printf("%d ", res[i]);
			}
			printf("\n");
		} else {
			memset(mark, 0, sizeof(mark));
			dfs(1, -1, 1, n);
			printf("1\n");
			for (int i = 1, cnt = 0; i <= nr && cnt < (k + 1) / 2; i += 2) {
				printf("%d ", res[i]);
				cnt++;
			}
			printf("\n");
		}
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
