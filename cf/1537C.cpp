// https://codeforces.com/contest/1537/problem/C
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

const int nm = 200002;

int n, a[nm];


void solve(int test) {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int minDiff = 1e9, ri = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i + 1] - a[i] < minDiff) {
			minDiff = a[i + 1] - a[i];
			ri = i;
		}
	}
	cout << a[ri] << " ";
	for (int i = ri + 2; i <= n; ++i) {
		cout << a[i] << " ";
	}
	for (int i = 1; i < ri; ++i) {
		cout << a[i] << " ";
	}
	cout << a[ri + 1] << "\n";
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