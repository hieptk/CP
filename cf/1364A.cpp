// https://codeforces.com/contest/1364/problem/A
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

int n, x, a[nm], s[nm];

void solve() {
	scanf("%d%d", &n, &x);
	int res = -1;
	int fi = -1;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] %= x;
		s[i] = (s[i - 1] + a[i]) % x;
		if (s[i]) {
			res = i;
			if (fi == -1) {
				fi = i;
			}
		} else if (fi != -1) {
			res = max(res, i - fi);
		}
	}
	printf("%d\n", res);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		solve();
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
