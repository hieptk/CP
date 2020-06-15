// https://codeforces.com/contest/1361/problem/A
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 500002;

int n, m;
vector<int> adj[nm];
pair<int, int> a[nm];
int b[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[u].eb(v);
		adj[v].eb(u);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i) {
		b[i] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (b[a[i].se] != a[i].fi) {
			printf("-1\n");
			return 0;
		}
		for (int j: adj[a[i].se]) {
			if (b[j] == a[i].fi) {
				b[j]++;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", a[i].se);
	}
}
