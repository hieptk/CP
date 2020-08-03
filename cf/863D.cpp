// https://codeforces.com/contest/863/problem/D
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

const int nm = 200002;
const int mm = 102;

struct query {
	int t, l, r;
};

int n, q, m, a[nm];
query c[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= q; ++i) {
		cin >> c[i].t >> c[i].l >> c[i].r;
	}
	for (int i = 1; i <= m; ++i) {
		int u;
		cin >> u;
		for (int j = q; j >= 1; --j) {
			if (c[j].l > u || c[j].r < u) {
				continue;
			}
			if (c[j].t == 1) {
				if(u == c[j].l) {
					u = c[j].r;
				} else {
					u--;
				}
			} else {
				u = c[j].r + c[j].l - u;
			}
		}
		cout << a[u] << " ";
	}
}

