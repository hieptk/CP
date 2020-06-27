// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2756
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;

int n, m;
vector<int> adj[nm];
int d, num[nm], low[nm];
int ns, st[nm];
int nc, comp[nm];
unordered_map<string, int> id;

void dfs(int i) {
	num[i] = low[i] = ++d;
	st[++ns] = i;
	for (int j: adj[i]) {
		if (!comp[j]) {
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
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		num[i] = comp[i] = 0;
	}
	id.clear();
	string s, t;
	getline(cin, s);
	for (int i = 1; i <= n; ++i) {
		getline(cin, s);
		id[s] = i;
	}
	d = nc = 0;
	for (int i = 1; i <= m; ++i) {
		getline(cin, s);
		getline(cin, t);
		adj[id[s]].eb(id[t]);
	}
	for (int i = 1; i <= n; ++i) {
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
	do {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}
		solve();
	} while (1);
}

