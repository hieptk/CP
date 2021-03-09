// https://codeforces.com/contest/1493/problem/A
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n, k;
		cin >> n >> k;
		int first = (k + 1) / 2;
		int res = n - first + 1;
		if (first <= k) {
			res--;
		}
		cout << res << "\n";
		for (int i = first; i <= n; ++i) {
			if (i != k) {
				cout << i << " ";
			}
		}
		cout << "\n";
	}
}
