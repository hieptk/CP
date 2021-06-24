// https://codeforces.com/contest/1537/submission/119991551
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

static const int nm = 52;

int n, a[nm];

void solve() {
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum < n) {
		cout << "1\n";
	} else {
		cout << sum - n << "\n";
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
#ifdef LOCAL
	cout << setprecision(3) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}