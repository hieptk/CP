// https://codeforces.com/contest/1363/problem/F
// https://codeforces.com/blog/entry/52376
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 2002;

int n;
char s[nm], t[nm];
int f[nm][nm];
int cnts[26][nm], cntt[26][nm];
bool ok[nm][nm];

void solve() {
	scanf("%d%s%s", &n, s, t);
	for (int i = 0; i < 26; ++i) {
		cnts[i][n + 1] = cntt[i][n + 1] = 0;
		for (int j = n; j >= 1; --j) {
			cnts[i][j] = cnts[i][j + 1] + (s[j - 1] - 'a' == i);
			cntt[i][j] = cntt[i][j + 1] + (t[j - 1] - 'a' == i);
		}
		if (cnts[i][1] != cntt[i][1]) {
			printf("-1\n");
			return;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			f[i][j] = max(f[i][j - 1], f[i - 1][j]);
			if (s[i - 1] == t[j - 1]) {
				bool ok = 1;
				for (int k = 0; k < 26; ++k) {
					if (cnts[k][i + 1] < cntt[k][j + 1]) {
						ok = 0;
						break;
					}
				}
				if (ok) {
					f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
				}
			}
		}
	}
	printf("%d\n", n - f[n][n]);
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
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
