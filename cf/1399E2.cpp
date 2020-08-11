// https://codeforces.com/contest/1399/problem/E2
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

const int nm = 100002;
const int mm = 2100000;
const int inf = 1e9;

struct edge {
	int u, v, c;
	ll w;
	int cnt;
	bool operator<(const edge &other) const {
		return ((w + 1) / 2) * cnt < ((other.w + 1) / 2) * other.cnt;
	}
};

int n;
ll s;
edge a[nm];
vector<int> adj[nm];
int nb, nc;
edge b[nm], c[nm];
int nd, ne;
ll d[mm], e[mm];

int other(int e, int i) {
	return a[e].u ^ a[e].v ^ i;
}

int dfs(int i, int p) {
	bool isLeaf = 1;
	int cnt = 0;
	for (int e: adj[i]) {
		int j = other(e, i);
		if (j != p) {
			isLeaf = 0;
			a[e].cnt = dfs(j, i);
			cnt += a[e].cnt;
		}
	}
	if (isLeaf) {
		return 1;
	}
	return cnt;
}

void calc(edge a[], int na, ll b[], int &nb) {
	priority_queue<edge> q;
	ll sum = 0;
	for (int i = 1; i <= na; ++i) {
		q.emplace(a[i]);
		sum += a[i].w * a[i].cnt;
	}
	nb = 0;
	while (sum > 0) {
		edge e = q.top();
		q.pop();
		ll w = ((e.w + 1) / 2) * e.cnt;
		nb++;
		b[nb] = b[nb - 1] + w;
		sum -= w;
		e.w >>= 1;
		q.emplace(e);
	}
}

void solve() {
	cin >> n >> s;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
	}
	for (int i = 1; i < n; ++i) {
		cin >> a[i].u >> a[i].v >> a[i].w >> a[i].c;
		adj[a[i].u].eb(i);
		adj[a[i].v].eb(i);
		a[i].cnt = 0;
	}
	dfs(1, -1);
	nb = nc = 0;
	ll sum = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i].c == 1) {
			b[++nb] = a[i];
		} else {
			c[++nc] = a[i];
		}
		sum += a[i].w * a[i].cnt;
	}
	calc(b, nb, d, nd);
	calc(c, nc, e, ne);
	int res = inf;
	int j = ne + 1;
	for (int i = 0; i <= nd; ++i) {
		while (j > 0 && sum - (d[i] + e[j - 1]) <= s) {
			j--;
		}
		if (j <= ne && sum - (d[i] + e[j]) <= s) {
			res = min(res, i + 2 * j);
		}
	}
	cout << res << "\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
