// https://codeforces.com/contest/1537/problem/B
#include <bits/stdc++.h>

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

typedef long long ll;
typedef long double ld;

using namespace std;

ll dist(int u, int v, int x, int y) {
	return abs(u - x) + abs(v - y);
}

void solve(int test) {
	int m, n, u, v;
	cin >> m >> n >> u >> v;
	int x[] = {1, 1, m, m};
	int y[] = {1, n, 1, n};
	ll res = 0;
	int ri = -1, rj = -1;
	for (int i = 0; i < 4; ++i) {
		for (int j = i; j < 4; ++j) {
			ll tmp = dist(u, v, x[i], y[i]) + dist(x[i], y[i], x[j], y[j]) + dist(x[j], y[j], u, v);
			if (tmp > res) {
				res = tmp;
				ri = i;
				rj = j;
			}
		}
	}
	cout << x[ri] << " " << y[ri] << " " << x[rj] << " " << y[rj] << "\n";
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
	cout << setprecision(3) << fixed << (double) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}