// https://codeforces.com/contest/1499/problem/D
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int mm = 20000002;

int factor[mm], cntfactor[mm];
ll c, d, x;

void solve() {
	cin >> c >> d >> x;
	ll res = 0;
	for (ll g = 1; g * g <= x; ++g) {
		if (x % g == 0) {
			if ((x + d * g) % c == 0) {
				ll l = (x + d * g) / c;
				if (l % g == 0) {
					res += 1ll << cntfactor[l / g];
				}
			}
			if (x / g > g && (x + d * x / g) % c == 0) {
				ll l = (x + d * x / g) / c;
				if (l % (x / g) == 0) {
					res += 1ll << cntfactor[l / (x / g)];
				}
			}
		}
	}
	cout << res << "\n";
}

void init() {
	for (int i = 2; i < mm; ++i) {
		if (!factor[i]) {
			cntfactor[i] = 1;
			for (ll j = (ll) i * i; j < mm; j += i) {
				factor[j] = i;
			}
		} else {
			if ((i / factor[i]) % factor[i] == 0) {
				cntfactor[i] = cntfactor[i / factor[i]];
			} else {
				cntfactor[i] = cntfactor[i / factor[i]] + 1;
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	init();

	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	auto begin = clock();
	for (int i = 1; i <= t; ++i) {
		solve();
	}
#ifdef LOCAL
	cout << setprecision(3) << fixed << (double) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}

