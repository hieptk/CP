// https://codeforces.com/gym/102500/problem/E
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double

using namespace std;

const ld eps = 1e-9;

ld a[10], b;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a[1] >> a[2] >> a[3] >> a[4] >> b;
	sort(a + 1, a + 5);
	if (a[2] + a[3] + a[4] < 3.0 * b + eps) {
		cout << "infinite\n";
		return 0;
	}
	if (a[1] + a[2] + a[3] > 3.0 * b + eps) {
		cout << "impossible\n";
		return 0;
	}
	cout << setprecision(2) << fixed << 3.0 * b - a[2] - a[3] << "\n";
}

