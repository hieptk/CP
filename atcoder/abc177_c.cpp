// https://atcoder.jp/contests/abc177/tasks/abc177_c
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const ll mod = 1000000007;
const int nm = 200002;

int n;
ll a[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	ll s = 0;
	ll res = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		res = (res + a[i] * s) % mod;
		s = (s + a[i]) % mod;
	}
	cout << res << "\n";
}

