// https://atcoder.jp/contests/aising2020/tasks/aising2020_b
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
	int n;
	cin >> n;
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		int x;
		cin >> x;
		if (i % 2 == 1 && x % 2 == 1) {
			res++;
		}
	}
	cout << res << "\n";
}

