// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_a
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll x, y, z;
	cin >> x >> y >> z;
	// x / y < z / ?
	ll res = z * y / x;
	if (z * y % x == 0) {
		res--;
	}
	cout << res << "\n";
}

