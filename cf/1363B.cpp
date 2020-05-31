// https://codeforces.com/contest/1363/problem/B
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;

int n;
char s[nm];
int sum[nm];

void solve() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + s[i - 1] - '0';
	}
	int res = n;
	for (int i = 0; i <= n; ++i) {
		res = min(res, sum[i] + n - i - (sum[n] - sum[i]));
		res = min(res, i - sum[i] + sum[n] - sum[i]);
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
}

