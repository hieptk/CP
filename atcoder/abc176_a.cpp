// https://atcoder.jp/contests/abc176/tasks/abc176_a
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n, x, t;
	cin >> n >> x >> t;
	cout << t * ((n + x - 1) / x) << "\n";
}

