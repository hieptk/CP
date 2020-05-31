// https://codeforces.com/contest/700/problem/C
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;
const int mm = 30002;
const ll inf = 1e18;

struct rec {
	int u, v;
	ll w;
};

int n, m, s, t;
vector<int> adj[nm];
rec edge[mm];
ll d[nm];
int trace[nm];
bool used[mm];
int ii;
int cnt, num[nm], low[nm], par[nm];

int other(int e, int i) {
	return edge[e].u ^ edge[e].v ^ i;
}

void dijkstra() {
	priority_queue<pair<ll, int>> q;
	q.emplace(0, s);
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	while (!q.empty()) {
		ll di = -q.top().fi;
		int i = q.top().se;
		q.pop();
		if (di != d[i]) {
			continue;
		}
		for (int e: adj[i]) {
			int j = other(e, i);
			if (d[j] > di + edge[e].w) {
				d[j] = di + edge[e].w;
				q.emplace(-d[j], j);
				trace[j] = e;
			}
		}
	}
}

void dfs(int i, int p, int rm) {
	num[i] = low[i] = ++cnt;
	par[i] = p;
	for (int e: adj[i]) {
		if (e == rm || e == p) {
			continue;
		}
		int j = other(e, i);
		if (!num[j]) {
			dfs(j, e, rm);
			low[i] = min(low[i], low[j]);
		} else {
			low[i] = min(low[i], num[j]);
		}
	}
}

ll try_remove(int e) {
	cnt = 0;
	memset(num, 0, sizeof(num));
	dfs(s, -1, e);
	if (!num[t]) {
		ii = -1;
		return edge[e].w;
	}
	ll res = inf;
	int i = t;
	while (i != s) {
		int e = par[i];
		if (low[i] >= num[i]) {
			if (edge[e].w < res) {
				res = edge[e].w;
				ii = e;
			}
		}
		i = other(e, i);
	}
	return res + edge[e].w;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		edge[i] = {u, v, w};
		adj[u].eb(i);
		adj[v].eb(i);
	}
	dijkstra();
	if (d[t] > inf) {
		printf("0\n0\n");
		return 0;
	}

	int i = t;
	while (i != s) {
		int e = trace[i];
		used[e] = 1;
		i = other(e, i);
	}
	ll res = inf;
	int e1, e2;
	for (int i = 1; i <= m; ++i) {
		if (used[i]) {
			ll tmp = try_remove(i);
			if (tmp < res) {
				res = tmp;
				e1 = i;
				e2 = ii;
			}
		}
	}
	if (res == inf) {
		cout << "-1\n";
		return 0;
	}
	cout << res << "\n";
	if (e2 == -1) {
		cout << "1\n" << e1 << "\n";
	} else {
		cout << "2\n" << e1 << " " << e2 << "\n";
	}
}

