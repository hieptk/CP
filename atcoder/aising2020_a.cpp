// https://atcoder.jp/contests/aising2020/tasks/aising2020_a
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll l, r, d;
	cin >> l >> r >> d;
	ll res = 0;
	for (ll i = l; i <= r; ++i) {
		res += (i % d == 0);
	}
	cout << res << "\n";
}

