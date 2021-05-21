// https://codeforces.com/contest/1520/problem/A
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

bool seen[30];

void solve(int test) {
	int n;
	string s;
	cin >> n >> s;
	memset(seen, 0, sizeof(seen));
	for (int i = 0; i < n; ++i) {
		if (seen[s[i] - 'A']) {
			cout << "NO\n";
			return;
		}
		seen[s[i] - 'A'] = 1;
		while (i + 1 < n && s[i + 1] == s[i]) {
			i++;
		}
	}
	cout << "YES\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	auto begin = clock();
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
#ifdef LOCAL
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}
