// https://codeforces.com/contest/1520/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int nm = 102;

int n, a[nm][nm];

void solve(int test) {
	cin >> n;
	if (n == 1) {
		cout << "1\n";
		return;
	}
	if (n == 2) {
		cout << "-1\n";
		return;
	}
	if (n == 3) {
		cout << "2 9 7\n"
				"4 6 3\n"
				"1 8 5\n";
		return;
	}
	int cnt = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; j += 2) {
			a[i][j] = cnt++;
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j <= n; j += 2) {
			a[i][j] = cnt++;
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
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
