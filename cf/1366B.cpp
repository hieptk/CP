// https://codeforces.com/contest/1366/problem/B
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 102;

int n, m, x;
int l[nm], r[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> x >> m;
		for (int i = 1; i <= m; ++i) {
			cin >> l[i] >> r[i];
		}
		int u = x, v = x;
		for (int i = 1; i<= m; ++i) {
			if (r[i] < u || l[i] > v) {
				continue;
			}
			u = min(u, l[i]);
			v = max(v, r[i]);
		}
		cout << v - u + 1 << "\n";
	}
}
