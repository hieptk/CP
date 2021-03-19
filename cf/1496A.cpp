// https://codeforces.com/contest/1496/problem/A
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, k;
string s;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k >> s;
		if (n <= 2 * k) {
			cout << "NO\n";
			continue;
		}
		bool ok = 1;
		for (int i = 0; i < k; ++i) {
			if (s[i] != s[n - 1 - i]) {
				ok = 0;
				break;
			}
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

