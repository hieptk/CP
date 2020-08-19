// https://codeforces.com/gym/102500/problem/I
#include <bits/stdc++.h>

using namespace std;

const int nm = 1000002;

int n, a[nm], b[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
	int i, j;
	for (i = 1; i <= n; ++i) {
		if (a[i] != b[i]) {
			break;
		}
	}
	if (i > n) {
		cout << "1 1\n";
		return 0;
	}
	for (j = n; j >= 1; --j) {
		if (a[j] != b[j]) {
			break;
		}
	}
	reverse(a + i, a + j + 1);
	for (int i = 1; i < n; ++i) {
		if (a[i] > a[i + 1]) {
			cout << "impossible\n";
			return 0;
		}
	}
	cout << i << " " << j << "\n";
}
