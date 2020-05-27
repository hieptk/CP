// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=251
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 101;

int n;
vector<int> adj[nm];
int d, num[nm], low[nm], par[nm], nchild[nm];
bool cut[nm];

void dfs(int i, int p) {
	par[i] = p;
	nchild[i] = 0;
	num[i] = low[i] = ++d;
	for (int j: adj[i]) {
		if (j != p) {
			if (!num[j]) {
				nchild[i]++;
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
	do {
		cin >> n;
		if (!n) {
			break;
		}
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
		}
		do {
			int u;
			cin >> u;
			if (!u) {
				break;
			}
			string s;
			getline(cin, s);
			stringstream ss(s);
			int v;
			while (ss >> v) {
				adj[u].eb(v);
				adj[v].eb(u);
			}
		} while (1);
		d = 0;
		memset(num, 0, sizeof(num));
		for (int i = 1; i <= n; ++i) {
			if (!num[i]) {
				dfs(i, -1);
			}
		}
		memset(cut, 0, sizeof(cut));
		for (int i = 1; i <= n; ++i) {
			if (par[i] != -1) {
				int u = par[i];
				if (par[u] != -1 && low[i] >= num[u]) {
					cut[u] = 1;
				}
			} else if (nchild[i] >= 2){
				cut[i] = 1;
			}
		}
		int res = 0;
		for (int i = 1; i <= n; ++i) {
			res += cut[i];
		}
		printf("%d\n", res);
	} while (1);
}


