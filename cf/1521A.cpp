// https://codeforces.com/contest/1521/problem/A
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

void solve(int test) {
	ll a, b;
	cin >> a >> b;
	if (b == 1) {
		cout << "NO\n";
		return;
	}
	ll x = a * b;
	ll y = a;
	ll z = x + y; // a * (b + 1)
	cout << "YES\n" << x << " " << y << " " << z << "\n";
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
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}
