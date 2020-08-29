// https://atcoder.jp/contests/abc176/tasks/abc176_d
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 1002;
const int inf = 1e9;
const int x[] = {-1, 0, 0, 1};
const int y[] = {0, -1, 1, 0};

int m, n;
int u, v, s, t;
char a[nm][nm];
int d[nm][nm];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> q;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n >> u >> v >> s >> t;
	u--;
	v--;
	s--;
	t--;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
	}
	memset(d, 0x3f, sizeof(d));
	d[u][v] = 0;
	q.emplace(0, u, v);
	while (!q.empty()) {
		int di, u, v;
		tie(di, u, v) = q.top();
		q.pop();
		if (di != d[u][v]) {
			continue;
		}
		for (int i = 0; i < 4; ++i) {
			int u2 = u + x[i], v2 = v + y[i];
			if (u2 >= 0 && u2 < m && v2 >= 0 && v2 < n && a[u2][v2] == '.' && d[u2][v2] > d[u][v]) {
				d[u2][v2] = d[u][v];
				q.emplace(d[u2][v2], u2, v2);
			}
		}
		for (int u2 = max(u - 2, 0); u2 <= u + 2 && u2 < m; ++u2) {
			for (int v2 = max(v - 2, 0); v2 <= v + 2 && v2 < n; ++v2) {
				if (a[u2][v2] == '.' && d[u2][v2] > d[u][v] + 1) {
					d[u2][v2] = d[u][v] + 1;
					q.emplace(d[u2][v2], u2, v2);
				}
			}
		}
	}
	cout << (d[s][t] < inf ? d[s][t] : -1) << "\n";
}

