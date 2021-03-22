// https://codeforces.com/contest/1499/problem/A
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
	int n, k1, k2, b, w;
	cin >> n >> k1 >> k2 >> w >> b;
	if (2 * w <= k1 + k2 && 2 * b <= 2 * n - k1 - k2) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}

