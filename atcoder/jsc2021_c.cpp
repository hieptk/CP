// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int l, r;

int doit(int n) {
	int res = 1;
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			// gcd is i
			if (n - i >= l) {
				res = max(res, i);
			}
			// gcd is n/i
			if (n - n / i >= l) {
				res = max(res, n / i);
			}
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> r;
	int res = 1;
	for (int i = l; i <= r; ++i) {
		res = max(res, doit(i));
	}
	cout << res << "\n";
}

