// https://atcoder.jp/contests/abc169/tasks/abc169_c
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ll a;
	long double b;
	cin >> a >> b;
	ll tmp = a * (ll) ((b + 1e-6) * 100.0);
	cout << tmp / 100 << "\n";
}

