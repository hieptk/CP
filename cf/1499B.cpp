// https://codeforces.com/contest/1499/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	int last00 = -1, first11 = n;
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] == '0' && s[i + 1] == '0') {
			last00 = i;
		} else if (first11 == n && s[i] == '1' && s[i + 1] == '1') {
			first11 = i;
		}
	}
	cout << (last00 < first11 ? "YES\n" : "NO\n");
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}

