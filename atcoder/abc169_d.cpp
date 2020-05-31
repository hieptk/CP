// https://atcoder.jp/contests/abc169/tasks/abc169_d
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

ll n;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> n;
	ll res = 0;
	for (ll i = 2; i * i <= n; i++) {
		int s = 0;
		while (n % i == 0) {
			s++;
			n /= i;
		}
		int j = 0;
		while ((j + 1) * (j + 2) / 2 <= s) {
			j++;
		}
		res += j;
	}
	if (n > 1) {
		res++;
	}
	cout << res << "\n";
}

