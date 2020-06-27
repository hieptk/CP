// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=183
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 27;

int n, m;
vector<int> adj[nm];
int d, num[nm], low[nm];
int nc, comp[nm];
int ns, st[nm];
unordered_map<string, int> name2id;
string names[nm];
vector<int> mem[nm];

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
			mem[nc].eb(j);
		} while (j != i);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 0;
	do {
		cin >> n >> m;
		if (!n && !m) {
			break;
		}
		if (t > 0) {
			cout << "\n";
		}
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			mem[i].clear();
		}
		name2id.clear();
		int nn = 0;
		for (int i = 1; i <= m; ++i) {
			string su, sv;
			cin >> su >> sv;
			if (!name2id.count(su)) {
				name2id[su] = ++nn;
				names[nn] = su;
			}
			if (!name2id.count(sv)) {
				name2id[sv] = ++nn;
				names[nn] = sv;
			}
			int u = name2id[su], v = name2id[sv];
			adj[u].eb(v);
		}
		d = 0;
		memset(num, 0, sizeof(num));
		nc = 0;
		memset(comp, 0, sizeof(comp));
		for (int i = 1; i <= n; ++i) {
			if (!num[i]) {
				ns = 0;
				dfs(i);
			}
		}

		cout << "Calling circles for data set " << ++t << ":\n";
		for (int i = 1; i <= nc; ++i) {
			for (int j = 0; j + 1 < mem[i].size(); ++j) {
				cout << names[mem[i][j]] << ", ";
			}
			cout << names[mem[i].back()] << "\n";
		}
	} while (1);
}

