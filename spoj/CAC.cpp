//https://www.spoj.com/problems/CAC/
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 83;

int n, m;
vector<int> adj[nm];
int dep[nm], mark[nm];
int d;
unsigned ll res;

void dfs(int i, int p, int d) {
	mark[i] = 1;
	dep[i] = d;
	for (int j: adj[i]) {
		if (j != p) {
			if (!mark[j]) {
				dfs(j, i, d + 1);
			} else if (mark[j] == 1) {
				res *= dep[i] - dep[j] + 1;
			}
		}
	}
	mark[i] = 2;
}

void solve(int test) {
	printf("Case %d: ", test);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
	}

	d = 0;
	memset(mark, 0, sizeof(mark));
	res = 1;
	for (int i = 1; i <= n; ++i) {
		if (!mark[i]) {
			dfs(i, -1, 0);
		}
	}
	printf("%llu\n", res);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}


