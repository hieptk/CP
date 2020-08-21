// https://codeforces.com/gym/102500/problem/G
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double

using namespace std;

const int nm = 502;

int n, k;
ld a[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	if (k == 1) {
		for (int i = 0; i < n; ++i) {
			cout << 100.0 / n << " ";
		}
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		ld s = a[i];
		ld res = 0;
		for (int d = 1; d <= n - k + 1; ++d) {
			ld p = s * k * (k - 1) / ((n - d) * (n - d + 1));
			for (int j = 0; j <= d - 2; ++j) {
				p = p * (n - k - j) / (n - j);
			}
			res += p;
			s += a[((i - d) % n + n) % n];
		}
		cout << setprecision(7) << fixed << res << " ";
	}
}

