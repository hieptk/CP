// https://codeforces.com/contest/1521/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int nm = 100002;

int n, a[nm];

void solve(int test) {
	cin >> n;
	int imin = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (a[i] < a[imin]) {
			imin = i;
		}
	}

	cout << n - 1 << "\n";
	for (int i = 1; i < imin; ++i) {
		cout << i << " " << imin << " " << a[imin] + imin - i << " " << a[imin] << "\n";
	}
	for (int i = imin + 1; i <= n; ++i) {
		cout << i << " " << imin << " " << a[imin] + i - imin << " " << a[imin] << "\n";
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
