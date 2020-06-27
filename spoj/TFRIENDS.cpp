// https://www.spoj.com/problems/TFRIENDS/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 102;;

int n;
char adj[nm][nm];
int d, num[nm], low[nm];
int ns, st[nm];
int nc, comp[nm];

void dfs(int i) {
	num[i] = low[i] = ++d;
	st[++ns] = i;
	for (int j = 0; j < n; ++j) {
		if (adj[i][j] == 'Y' && !comp[j]) {
			if (!num[j]) {
				dfs(j);
				low[i] = min(low[i], low[j]);
			} else {
				low[i] = min(low[i], num[j]);
			}
		}
	}
	if (low[i] == num[i]) {
		nc++;
		int j;
		do {
			j = st[ns--];
			comp[j] = nc;
		} while (j != i);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> adj[i];
	}
	memset(num, 0, sizeof(num));
	memset(comp, 0, sizeof(comp));
	d = nc = 0;
	for (int i = 0; i < n; ++i) {
		if (!comp[i]) {
			ns = 0;
			dfs(i);
		}
	}

	cout << nc << "\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

