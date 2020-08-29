// https://atcoder.jp/contests/abc177/tasks/abc177_b
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	int res = m;
	for (int i = 0; i + m - 1 < n; ++i) {
		int d = 0;
		for (int j = 0; j < m; ++j) {
			d += (s[i + j] != t[j]);
		}
		res = min(res, d);
	}
	cout << res << "\n";
}

