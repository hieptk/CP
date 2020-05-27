// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=551
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 1002;
const int mm = nm * (nm - 1) / 2;

int n, m;
vector<int> adj[nm];
pair<int, int> edge[mm];
int d, num[nm], low[nm];
int par[nm];

void dfs(int i, int p) {
	num[i] = low[i] = ++d;
	par[i] = p;
	for (int j: adj[i]) {
		if (j != p) {
			if (!num[j]) {
				dfs(j, i);
				low[i] = min(low[i], low[j]);
			} else {
				low[i] = min(low[i], num[j]);
			}
		}
	}
}

bool is_bridge(int i) {
	if (edge[i].first == par[edge[i].second]) {
		return low[edge[i].second] >= num[edge[i].second];
	}
	if (edge[i].second == par[edge[i].first]) {
		return low[edge[i].first] >= num[edge[i].first];
	}
	return 0;
}

void solve(int test) {
	printf("%d\n\n", test);
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
		edge[i] = {u, v};
	}
	d = 0;
	memset(num, 0, sizeof(num));
	for (int i = 1; i <= n; ++i) {
		if (!num[i]) {
			dfs(i, -1);
		}
	}
	for (int i = 1; i <= m; ++i) {
		if (is_bridge(i)) {
			printf("%d %d\n%d %d\n", edge[i].first, edge[i].second, edge[i].second, edge[i].first);
		} else {
			if (edge[i].first == par[edge[i].second]) {
				printf("%d %d\n", edge[i].first, edge[i].second);
			} else if (edge[i].second == par[edge[i].first]) {
				printf("%d %d\n", edge[i].second, edge[i].first);
			} else if (num[edge[i].first] < num[edge[i].second]) {
				printf("%d %d\n", edge[i].second, edge[i].first);
			} else {
				printf("%d %d\n", edge[i].first, edge[i].second);
			}
		}
	}
	printf("#\n");
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t = 0;
	while (scanf("%d%d", &n, &m) == 2) {
		if (!n && !m) {
			break;
		}
		solve(++t);
	}
}


