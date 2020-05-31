// https://codeforces.com/contest/1363/problem/A
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

int n, x;

void solve() {
	scanf("%d%d", &n, &x);
	int o = 0, e = 0;
	for (int i = 1; i <= n; ++i) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp % 2) {
			o++;
		} else {
			e++;
		}
	}
	for (int i = max(x - o, 0); i <= e && i < x; ++i) {
		if ((x - i) % 2) {
			printf("Yes\n");
			return;
		}
	}
	printf("No\n");
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
