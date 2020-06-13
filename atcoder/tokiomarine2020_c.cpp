// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;

int n, m, a[nm], a2[nm];
pair<int, int> b[2 * nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			b[2 * j - 1] = {j - a[j], 0};
			b[2 * j] = {j + a[j], 1};
		}
		sort(b + 1, b + 2 * n + 1);
		int u = 1;
		int d = 0;
		bool diff = 0;
		for (int j = 1; j <= n; ++j) {
			while (u <= 2 * n && (b[u].fi < j || (b[u].fi == j && b[u].se == 0))) {
				if (b[u].se == 0) {
					d++;
				} else {
					d--;
				}
				u++;
			}
			if (a[j] != d) {
				a[j] = d;
				diff = 1;
			}
		}
		if (!diff) {
			break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i]);
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}

