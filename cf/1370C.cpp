// https://codeforces.com/contest/1370/problem/C
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const string names[] = {"FastestFinger", "Ashishgup"};

unordered_map<int, int> f;

int calc(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2) {
		return 1;
	}
	if (n & 1) {
		return 1;
	}
	if (f.count(n)) {
		return f[n];
	}
	int n2 = n;
	while (!(n & 1)) {
		n >>= 1;
	}
	if (n > 1 && n2 / n > 2) {
		return f[n2] = 1;
	}
	for (int i = 3; i * i <= n; ++i) {
		if (n % i == 0) {
			if (!calc(n2 / i)) {
				return f[n2] = 1;
			}
			if (!calc(n2 / (n / i))) {
				return f[n2] = 1;
			}
		}
	}
	return f[n2] = 0;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
//	t = 100;
	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;
//		n = 1000000000 - 2 * i + 2;
		cout << names[calc(n)] << "\n";
	}
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}
