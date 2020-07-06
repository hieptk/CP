// https://codeforces.com/contest/22/problem/E
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

int n, a[nm], deg[nm];
int nc, comp[nm];
int b[nm], e[nm];

void dfs(int i) {
	comp[i] = nc;
	e[nc] = i;
	if (!comp[a[i]]) {
		dfs(a[i]);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		deg[a[i]]++;
	}
	for (int i = 1; i <= n; ++i) {
		if (!deg[i]) {
			nc++;
			b[nc] = i;
			dfs(i);
		}
	}
	int nc2 = nc;
	for (int i = 1; i <= n; ++i) {
		if (!comp[i]) {
			nc++;
			b[nc] = i;
			dfs(i);
		}
	}
	if (nc == 1 && nc2 == 0) {
		printf("0\n");
		return 0;
	}
	printf("%d\n", nc);
	for (int i = 1; i <= nc; ++i) {
		int j = i % nc + 1;
		printf("%d %d\n", e[i], b[j]);
	}
}

