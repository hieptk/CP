// https://codeforces.com/contest/1366/problem/C
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 32;

int m, n, a[nm][nm];
int cnt[2 * nm][2];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				cin >> a[i][j];
				int u = min(i + j - 2, m + n - 2 - (i + j - 2));
				cnt[u][a[i][j]]++;
			}
		}
		int res = 0;
		for (int i = 0; i < m + n -2 - i; ++i) {
			res += min(cnt[i][0], cnt[i][1]);
		}
		cout << res << "\n";
	}
}
