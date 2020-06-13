// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_b
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll a, b, va, vb, t;
	cin >> a >> va >> b >> vb >> t;
	if (abs(a - b) <= t * (va - vb)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}

