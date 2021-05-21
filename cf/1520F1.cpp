// https://codeforces.com/contest/1520/problem/F1
#include <bits/stdc++.h>

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	auto begin = clock();
#endif
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n, t, k;
	cin >> n >> t >> k;
	int l = k, r = n - 1, res = n;
	while (l <= r) {
		int mid = (l + r) >> 1;
		cout << "? 1 " << mid << "\n";
		cout.flush();
		int ret;
		cin >> ret;
		int n0 = mid - ret;
		if (n0 >= k) {
			res = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << "! " << res << "\n";

#ifdef LOCAL
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}
