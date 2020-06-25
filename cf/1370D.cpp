// https://codeforces.com/contest/1370/problem/D
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;
const int inf = 1000000000;

int n, k, a[nm];
int f[nm];

bool ok(int x) {
	f[1] = (a[1] <= x);
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 1];
		if (a[i] <= x) {
			f[i] = max(f[i], f[i - 2] + 1);
		}
	}
	if (k % 2) {
		if (f[n] >= (k + 1) / 2) {
			return 1;
		}
	} else {
		if (f[n - 1] >= k / 2) {
			return 1;
		}
	}
	f[1] = 0;
	for (int i = 2; i <= n; ++i) {
		f[i] = f[i - 1];
		if (a[i] <= x) {
			f[i] = max(f[i], f[i - 2] + 1);
		}
	}
	if (k % 2) {
		return f[n - 1] >= k / 2;
	}
	return f[n] >= k / 2;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int l = 1, r = inf, res = inf + 1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ok(mid)) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	printf("%d\n", res);
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}
