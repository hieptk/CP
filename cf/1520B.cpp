// https://codeforces.com/contest/1520/problem/B
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

void solve(int test) {
	ll n;
	cin >> n;
	if (n < 10) {
		cout << n << "\n";
		return;
	}
	queue<int> q;
	for (int i = 1; i <= 9; ++i) {
		q.push(i);
	}

	int res = 0;
	while (q.size()) {
		ll i = q.front();
		q.pop();
		res++;
		if (i * 10 + i % 10 <= n) {
			q.push(i * 10 + i % 10);
		}
	}
	cout << res << "\n";
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
