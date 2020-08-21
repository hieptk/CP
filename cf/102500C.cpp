// https://codeforces.com/gym/102500/problem/C
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double

using namespace std;

const int nm = 1002;
const int mm = 2002;

int n, l[nm], r[nm];
int m, a[mm];
vector<int> pos[nm];
int nr, res[2 * nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> l[i] >> r[i];
	}
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[j] >= l[i] && a[j] <= r[i]) {
				pos[i].eb(a[j]);
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (pos[i].size() > 2) {
			cout << "impossible\n";
			return 0;
		}
		if (pos[i].size() == 2) {
			continue;
		}
		if (i < n && r[i] == l[i + 1] && pos[i + 1].size() >= 2) {
			for (int j = r[i] - 1; ; --j) {
				if (pos[i].size() == 0 || j != pos[i][0]) {
					res[++nr] = j;
					pos[i].eb(j);
					break;
				}
			}
		} else if (pos[i].size() && pos[i][0] == r[i]) {
			res[++nr] = r[i] - 1;
			pos[i].eb(r[i] - 1);
		} else {
			res[++nr] = r[i];
			pos[i].eb(r[i]);
			if (i < n && r[i] == l[i + 1]) {
				pos[i + 1].eb(r[i]);
			}
		}
		if (pos[i].size() == 1) {
			for (int j = r[i] - 1; ; --j) {
				if (j != pos[i][0]) {
					res[++nr] = j;
					break;
				}
			}
		}
	}

	cout << nr << "\n";
	for (int i = 1; i <= nr; ++i) {
		cout << res[i] << " ";
	}

}

