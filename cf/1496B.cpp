// https://codeforces.com/contest/1496/problem/B
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n, k;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		set<int> x;
		int amax = -1;
		for (int i = 1; i <= n; ++i) {
			int y;
			cin >> y;
			x.insert(y);
			amax = max(amax, y);
		}
		if (!k) {
			cout << n << "\n";
			continue;
		}
		int mex = 0;
		while (x.count(mex)) {
			mex++;
		}
		if (mex == n) {
			cout << n + k << "\n";
			continue;
		}
		int y = (mex + amax + 1) / 2;
		if (x.count(y)) {
			cout << n << "\n";
		} else {
			cout << n + 1 << "\n";
		}
	}
}

