// https://codeforces.com/contest/1496/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 100002;

int n;
ll x[nm], y[nm];

bool cmp(ll a, ll b) {
	return abs(a) < abs(b);
}

void solve() {
	cin >> n;
	int nx = 0, ny = 0;
	for (int i = 1; i <= 2 * n; ++i) {
		int u, v;
		cin >> u >> v;
		if (u == 0) {
			y[++ny] = v;
		} else {
			x[++nx] = u;
		}
	}
	sort(x + 1, x + n + 1, cmp);
	sort(y + 1, y + n + 1, cmp);
	ld res = 0;
	for (int i = 1; i <= n; ++i) {
		res += sqrt(x[i] * x[i] + y[i] * y[i]);
	}
	cout << setprecision(10) << fixed << res << "\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

