// https://codeforces.com/contest/1400/problem/A
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

bool ok[52];

int n;
string s;

void solve(int test) {
	cin >> n >> s;
	string res;
	memset(ok, 0, sizeof(ok));
	for (int i = 0; i < n; ++i) {
		char y = '0';
		for (int j = 0; j < n; ++j) {
			if (!ok[j]) {
				y = s[i + j];
				break;
			}
		}
		res += y;
		for (int j = 0; j < n; ++j) {
			if (y == s[i + j]) {
				ok[j] = 1;
			}
		}
	}
	cout << res << "\n";
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
		solve(i);
	}
}
