// https://codeforces.com/contest/1499/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 100002;

int n;
ll a[nm];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll amin[2];
	amin[0] = 1e18;
	amin[1] = a[1];
	ll sum[2];
	sum[0] = 0;
	sum[1] = a[1];
	ll res = 1e18;
	for (int i = 2; i <= n; ++i) {
		sum[i % 2] += a[i];
		amin[i % 2] = min(amin[i % 2], a[i]);
		ll same = (sum[i % 2] - amin[i % 2]) + amin[i % 2] * (n - (i - 1) / 2);
		ll diff = (sum[1 - i % 2] - amin[1 - i % 2]) + amin[1 - i % 2] * (n - (i / 2) + 1);
		res = min(res, same + diff);
	}
	cout << res << "\n";
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

