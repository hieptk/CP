// https://codeforces.com/contest/1537/problem/D
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

// const int nm = 100002;

// int f[nm];

void solve(int test) {
	int n;
	cin >> n;
	if (n % 2) {
		cout << "Bob\n";
		return;
	}
	if (n & (n - 1)) {
		cout << "Alice\n";
		return;
	}
	int cnt = 0;
	while (n > 1) {
		cnt++;
		n >>= 1;
	}
	if (cnt & 1) {
		cout << "Bob\n";
	} else {
		cout << "Alice\n";
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	auto begin = clock();
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	// for (int i = 4; i < nm; ++i) {
		// set<int> x;
		// for (int j = 2; j * j <= i; ++j) {
			// if (i % j == 0) {
				// x.insert(f[i - j]);
				// x.insert(f[i - i / j]);
			// }
		// }
		// for (int j = 0; ; ++j) {
			// if (!x.count(j)) {
				// f[i] = j;
				// break;
			// }
		// }
		// if ((i & (i - 1)) == 0) {
			// cout << i << " " << f[i] << "\n";
		// }
	// }
	// return 0;
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
#ifdef LOCAL
	cout << setprecision(3) << fixed << (double) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}