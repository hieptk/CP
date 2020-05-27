// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=13&page=show_problem&problem=1140
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 102;

int n, m;
string name[nm];
int adj[nm][nm];
unordered_map<string, int> name2id;
int d, num[nm], low[nm], par[nm];
int nchild[nm];

void dfs(int i, int p) {
	num[i] = low[i] = ++d;
	par[i] = p;
	nchild[i] = 0;
	for (int j = 1; j <= n; ++j) {
		if (adj[i][j]) {
			if (!num[j]) {
				nchild[i]++;
				adj[j][i]--;
				dfs(j, i);
				low[i] = min(low[i], low[j]);
			} else {
				low[i] = min(low[i], num[j]);
			}
		}
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
		cin >> n;
		if (!n) {
			break;
		}
		if (t) {
			cout << "\n";
		}
		t++;
		name2id.clear();
		for (int i = 1; i <= n; ++i) {
			cin >> name[i];
			name2id[name[i]] = i;
		}
		cin >> m;
		memset(adj, 0, sizeof(adj));
		for (int i = 1; i <= m; ++i) {
			string x, y;
			cin >> x >> y;
			int u = name2id[x], v = name2id[y];
			adj[u][v]++;
			adj[v][u]++;
		}
		d = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; ++i) {
			if (!num[i]) {
				dfs(i, -1);
			}
		}

		set<string> cuts;
		for (int i = 1; i <= n; ++i) {
			if (par[i] != -1) {
				int u = par[i];
				if (par[u] != -1 && low[i] >= num[u]) {
					cuts.insert(name[u]);
				}
			} else if (nchild[i] >= 2) {
				cuts.insert(name[i]);
			}
		}
		cout << "City map #" << t << ": " << cuts.size() << " camera(s) found\n";
		for (string cut: cuts) {
			cout << cut << "\n";
		}
	} while (1);
}

