// https://www.codechef.com/AUG16/problems/CHEFRRUN
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1000002;

int n, a[nm];
int d[nm];
int mark[nm];

int dfs(int i) {
	mark[i] = 1;
	int res;
	if (!mark[a[i]]) {
		d[a[i]] = d[i] + 1;
		res = dfs(a[i]);
	} else if (mark[a[i]] == 1) {
		res = d[i] - d[a[i]] + 1;
	} else {
		res = 0;
	}
	mark[i] = 2;
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			a[i] = (i + a[i] + 1) % n;
			d[i] = 0;
			mark[i] = 0;
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			if (!d[i]) {
				d[i] = 1;
				res += dfs(i);
			}
		}
		printf("%d\n", res);
	}
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}

