// https://atcoder.jp/contests/abc176/tasks/abc176_c
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 200002;

int n;
ll a[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll s = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] < a[i - 1]) {
			s += a[i - 1] - a[i];
			a[i] = a[i - 1];
		}
	}
	cout << s << "\n";
}

