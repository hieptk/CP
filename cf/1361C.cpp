// https://codeforces.com/contest/1361/problem/C
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 500002;
const int mm = 1 << 20;

int n, a[2 * nm], a2[2 * nm];
vector<int> adj[mm];
bool used[nm], vs[mm];
int nr, cycle[2 * nm], cycle2[2 * nm];
int deg[mm];

int other(int i, int e) {
	return i ^ a2[(e << 1) - 1] ^ a2[e << 1];
}

void find_cycle(int i, int e = -1) {
	vs[i] = 1;
	while (adj[i].size()) {
		int e = adj[i].back();
		adj[i].pop_back();
		if (used[e]) {
			continue;
		}
		used[e] = 1;
		int j = other(i, e);
		find_cycle(j, e);
	}
	if (e != -1) {
		if (a2[(e << 1) - 1] == i) {
			cycle[++nr] = (e << 1) - 1;
			cycle[++nr] = e << 1;
		} else {
			cycle[++nr] = e << 1;
			cycle[++nr] = (e << 1) - 1;
		}
	}
}

bool ok(int m) {
	memset(deg, 0, sizeof(deg));
	int cntOdd = 0;
	for (int i = 1; i <= n; ++i) {
		int u = a2[(i << 1) - 1] = a[(i << 1) - 1] & m;
		int v = a2[i << 1] = a[i << 1] & m;
		deg[u]++;
		if (deg[u] == 1) {
			vs[u] = 0;
			adj[u].clear();
		}
		deg[v]++;
		if (deg[v] == 1) {
			vs[v] = 0;
			adj[v].clear();
		}
		adj[u].eb(i);
		adj[v].eb(i);
		if (u != v) {
			if (deg[u] & 1) {
				cntOdd++;
			} else {
				cntOdd--;
			}
			if (deg[v] & 1) {
				cntOdd++;
			} else {
				cntOdd--;
			}
		}
		used[i] = 0;
	}
	if (cntOdd) {
		return 0;
	}
	bool found = 0;
	for (int i = 0; i <= m; ++i) {
		if (deg[i]) {
			if (!found) {
				nr = 0;
				find_cycle(i);
				found = 1;
			} else if (!vs[i]) {
				return 0;
			}
		}
	}
	for (int i = 1; i <= (n << 1); ++i) {
		cycle2[i] = cycle[i];
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
//	n = 500000;
	for (int i = 1; i <= (n << 1); ++i) {
		scanf("%d", &a[i]);
//		a[i] = rand() % (1 << 20);
	}
	int l = 0, r = 20, res = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ok((1 << mid) - 1)) {
			res = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	printf("%d\n", res);
	for (int i = 1; i <= (n << 1); ++i) {
		printf("%d ", cycle2[i]);
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
