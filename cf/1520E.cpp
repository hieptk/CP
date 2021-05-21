// https://codeforces.com/contest/1520/problem/E
#include <bits/stdc++.h>

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int nm = 1000002;

int n;
string s;
int pos[nm];

void solve() {
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '*') {
			cnt++;
			pos[cnt] = i;
		}
	}
	ll res = 0;
	int m = (cnt + 1) / 2;
	for (int i = 1; i <= cnt; ++i) {
		res += abs(pos[m] - (m - i) - pos[i]);
	}
	cout << res << "\n";
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
		solve();
	}
#ifdef LOCAL
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}

