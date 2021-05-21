// https://codeforces.com/contest/1520/problem/F2
#include <bits/stdc++.h>

#define fi first
#define se second

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int nm = 200002;

int n, k;
map<pair<int, int>, int> query;
int tree[nm];

int get(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i -= i & (-i);
	}
	return res;
}

int getsum(int l, int r) {
	int add = get(r) - get(l - 1);
	auto it = query.find({l, r});
	if (it == query.end()) {
		cout << "? " << l << " " << r << "\n";
		cout.flush();
		int ret;
		cin >> ret;
		query[{l, r}] = ret - add;
		return ret;
	} else {
		return it->second + add;
	}
}

void add(int i) {
	while (i <= n) {
		tree[i]++;
		i += i & (-i);
	}
}

void solve() {
	int l = 1, r = n - 1, res = n;
	while (l <= r) {
		int m = (l + r) >> 1;
		int n0 = m - l + 1 - getsum(l, m);
		if (n0 >= k) {
			res = m;
			r = m - 1;
		} else {
			k -= n0;
			l = m + 1;
		}
	}
	cout << "! " << res << "\n";
	cout.flush();
	add(res);
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	auto begin = clock();
#endif
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int t;
	cin >> n >> t;
	for (int i = 1; i <= t; ++i) {
		cin >> k;
		if (k == -1) {
			return 0;
		}
		solve();
	}
#ifdef LOCAL
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}
