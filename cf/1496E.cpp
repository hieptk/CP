// https://codeforces.com/contest/1496/problem/E
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 502;

int m, n;
string a[nm];

void solve() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	if (n % 3 == 0 || n % 3 == 2) {
		for (int j = 1; j < n; j += 3) {
			for (int i = 0; i < m; ++i) {
				a[i][j] = 'X';
			}
			if (j + 2 < n) {
				bool found = 0;
				for (int i = 0; i < m; ++i) {
					if (a[i][j + 2] == 'X') {
						a[i][j + 1] = 'X';
						found = 1;
						if (j + 2 < n - 1) {
							break;
						}
					} else if (a[i][j + 1] == 'X') {
						a[i][j + 2] = 'X';
						found = 1;
						if (j + 2 < n - 1) {
							break;
						}
					}
				}
				if (!found) {
					a[0][j + 1] = a[0][j + 2] = 'X';
				}
			}
		}
	} else {
		for (int j = 0; j < n; j += 3) {
			for (int i = 0; i < m; ++i) {
				a[i][j] = 'X';
			}
			if (j + 2 < n) {
				bool found = 0;
				for (int i = 0; i < m; ++i) {
					if (a[i][j + 2] == 'X') {
						a[i][j + 1] = 'X';
						found = 1;
						break;
					} else if (a[i][j + 1] == 'X') {
						a[i][j + 2] = 'X';
						found = 1;
						if (j + 2 < n - 1) {
							break;
						}
					}
				}
				if (!found) {
					a[0][j + 1] = a[0][j + 2] = 'X';
				}
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		cout << a[i] << "\n";
	}
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

