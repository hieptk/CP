// https://codeforces.com/contest/1366/problem/E
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;
const ll mod = 998244353;

int n, m, a[nm], b[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &b[i]);
	}
	int j = n;
	ll res = 1;
	for (int i = m; i >= 1; --i) {
		int found = -1;
		while (j >= 1 && a[j] >= b[i]) {
			if (a[j] == b[i] && found == -1) {
				found = j;
			}
			j--;
		}
//		cout << i << " " << j << " " << found << "\n";
		if (found == -1) {
			printf("0\n");
			return 0;
		}
		if (i > 1) {
			res = (res * (found - j)) % mod;
		}
	}
	if (j > 0) {
		printf("0\n");
		return 0;
	}
	cout << res << "\n";
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
