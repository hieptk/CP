// https://atcoder.jp/contests/abc177/tasks/abc177_a
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
	ll d, t, s;
	cin >> d >> t >> s;
	cout << (t * s >= d ? "Yes\n" : "No\n");
}

