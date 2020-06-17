// https://codeforces.com/contest/1366/problem/A
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		ll a, b;
		cin >> a >> b;
		ll res = min(a, b / 2);
		res = max(res, min(b, a / 2));
		ld x = (2.0 * a - b) / 3, y = (2.0 * b - a) / 3;
		if (x > 1e-9 && y > 1e-9) {
			res = max(res, (ll) (x + y + 1e-9));
		}
		cout << res << "\n";
	}
}
