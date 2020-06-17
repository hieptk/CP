// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_d
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = (1 << 18) + 2;
const int mm = 100002;
const int nm2 = (1 << 9) + 2;

int n, w[nm], v[nm];
int f[nm2][mm];
int m;

int solve(int u, int l) {
	if (u < nm2) {
		return f[u][l];
	}
	int res = solve(u >> 1, l);
	if (w[u] <= l) {
		res = max(res, solve(u >> 1, l - w[u]) + v[u]);
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &v[i], &w[i]);
	}
	for (int i = 1; i < nm2 && i <= n; ++i) {
		for (int j = 1; j < mm; ++j) {
			f[i][j] = f[i >> 1][j];
			if (w[i] <= j) {
				f[i][j] = max(f[i][j], f[i >> 1][j - w[i]] + v[i]);
			}
		}
	}
	scanf("%d", &m);
	while (m--) {
		int u, l;
		scanf("%d%d", &u, &l);
		printf("%d\n", solve(u, l));
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}

