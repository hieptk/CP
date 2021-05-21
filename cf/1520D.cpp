// https://codeforces.com/contest/1520/problem/D
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int nm = 200002;

int n, a[nm], cnt[2 * nm];

void solve(int test) {
	cin >> n;
	ll res = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		res += cnt[a[i] - i + nm];
		cnt[a[i] - i + nm]++;
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
		solve(i);
	}
#ifdef LOCAL
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}
