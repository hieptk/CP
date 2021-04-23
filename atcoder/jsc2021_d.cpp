// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_d
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const ll mod = 1000000007;

ll n, p;

ll powmod(ll a, ll b) {
	if (!b) {
		return 1;
	}
	ll tmp = powmod(a, b >> 1);
	tmp = (tmp * tmp) % mod;
	if (b & 1) {
		tmp = (tmp * a) % mod;
	}
	return tmp;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	cout << ((p - 1) * powmod(p - 2, n - 1)) % mod << "\n";
}

