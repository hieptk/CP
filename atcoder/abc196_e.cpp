// https://atcoder.jp/contests/abc196/tasks/abc196_e
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 200200;
const ll inf = 1e9 + 10;

int n, m;
pair<int, ll> a[nm];
ll b[nm];
int nc;
ll c[nm];
pair<int, ll> d[nm];

pair<int, ll> calc(ll x) {
	pair<int, ll> res = {1, 0};
	for (int i = 1; i <= n; ++i) {
		if (a[i].first == 1) {
			res.second += a[i].second;
		} else if (a[i].first == 2) {
			if (x * res.first + res.second < a[i].second) {
				res.first = 0;
				res.second = a[i].second;
			}
		} else {
			if (x * res.first + res.second > a[i].second) {
				res.first = 0;
				res.second = a[i].second;
			}
		}
	}
	return res;
}

bool find_next() {
	ll l = c[nc] + 1, r = inf;
	c[nc + 1] = inf + 1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		auto tmp = calc(mid);
		if (tmp == d[nc]) {
			l = mid + 1;
		} else {
			c[nc + 1] = mid;
			d[nc + 1] = tmp;
			r = mid - 1;
		}
	}
	return c[nc + 1] <= inf;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(2512);
	cin >> n;
//	n = 200000;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i].second >> a[i].first;
//		a[i].first = rand() % 3 + 1;
//		a[i].second = rand() % 1000000000;
//		if (rand() % 2) {
//			a[i].second = -a[i].second;
//		}
	}
	cin >> m;
//	m = 200000;
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
//		b[i] = rand() % 1000000000;
	}

	c[1] = -inf;
	d[1] = calc(-inf);
	nc = 1;

	while (find_next()) {
		nc++;
	}

//	cout << nc << "\n";
//	for (int i = 1; i <= nc; ++i) {
//		cout << c[i] << " " << d[i].first << " " << d[i].second << "\n";
//	}

	for (int i = 1; i <= m; ++i) {
		int j = upper_bound(c + 1, c + nc + 1, b[i]) - c - 1;
		cout << b[i] * d[j].first + d[j].second << "\n";
	}
}

