// https://atcoder.jp/contests/abc176/tasks/abc176_e
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 300002;

vector<int> row[nm];
int cntcol[nm];
int m, n, k;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 1; i <= k; ++i) {
		int u, v;
		cin >> u >> v;
		row[u].eb(v);
		cntcol[v]++;
	}
	int cntmax = -1, nmax = 0;
	for (int i = 1; i <= n; ++i) {
		if (cntcol[i] > cntmax) {
			cntmax = cntcol[i];
			nmax = 1;
		} else if (cntcol[i] == cntmax) {
			nmax++;
		}
	}
	int res = 0;
	for (int i = 1; i <= m; ++i) {
		int cnt = 0;
		for (int j: row[i]) {
			if (cntcol[j] == cntmax) {
				cnt++;
			}
		}
		if (cnt < nmax) {
			res = max(res, (int) row[i].size() + cntmax);
		} else {
			res = max(res, (int) row[i].size() + cntmax - 1);
		}
	}
	cout << res << "\n";
}

