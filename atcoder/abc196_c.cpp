// https://atcoder.jp/contests/abc196/tasks/abc196_c
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin >> n;
	ll pow10 = 10;
	int res = 0;
	for (ll i = 1; i < 1000000; ++i) {
		if (i % pow10 == 0) {
			pow10 *= 10;
		}
		if (pow10 * i + i <= n) {
			res++;
		}
	}
	cout << res << "\n";
}

