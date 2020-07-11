// https://atcoder.jp/contests/aising2020/tasks/aising2020_c
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 10002;

ll f[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll n;
	cin >> n;
	for (ll x = 1; x * x <= n; ++x) {
		for (ll y = 1; y * y <= n; ++y) {
			for (ll z = 1; z * z <= n; ++z) {
				ll tmp = x * x + y * y + z * z + x * y + y * z + z * x;
				if (tmp <= n) {
					f[tmp]++;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << f[i] << "\n";
	}
}

