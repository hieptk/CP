// https://codeforces.com/contest/1363/problem/E
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;
const ll inf = 1e18;

int n;
ll a[nm];
int b[nm], c[nm];
vector<int> adj[nm];
ll f[nm];
int e1[nm], e2[nm];

void dfs(int i, int p, ll mina) {
	mina = min(mina, a[i]);
	if (b[i] && !c[i]) {
		e1[i] = 1;
	} else if (!b[i] && c[i]){
		e2[i] = 1;
	}
	ll res = 0;
	for (int j: adj[i]) {
		if (j != p) {
			dfs(j, i, mina);
			res += f[j];
			if (e1[j] > e2[j]) {
				e1[i] += e1[j] - e2[j];
			} else {
				e2[i] += e2[j] - e1[j];
			}
		}
	}
	res += mina * 2ll * min(e1[i], e2[i]);
	f[i] = res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%I64d%d%d", &a[i], &b[i], &c[i]);
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
	}
	dfs(1, -1, inf);
	if (e1[1] != e2[1]) {
		cout << "-1\n";
	} else {
		cout << f[1] << "\n";
	}
}
