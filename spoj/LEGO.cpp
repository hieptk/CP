// https://www.spoj.com/problems/LEGO/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

struct rec {
	int x1, y1, x2, y2;
};

const int nm = 100002;

int n;
rec a[nm];
vector<int> adj[nm];
bool vs[nm];

bool cmp(rec &a, rec &b) {
	if (a.y2 != b.y2) {
		return a.y2 < b.y2;
	}
	return a.x1 < b.x1;
}

void dfs(int i) {
	vs[i] = 1;
	for (int j: adj[i]) {
		if (!vs[j]) {
			dfs(j);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		int l = 1, r = n, res = n + 1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (a[mid].y2 < a[i].y1) {
				l = mid + 1;
			} else if (a[mid].y2 > a[i].y1) {
				r = mid - 1;
			} else if (a[mid].x2 <= a[i].x1) {
				l = mid + 1;
			} else if (a[mid].x1 >= a[i].x2) {
				r = mid - 1;
			} else {
				res = mid;
				r = mid - 1;
			}
		}
		while (res <= n && a[res].y2 == a[i].y1 && a[res].x2 > a[i].x1 && a[res].x1 < a[i].x2) {
			adj[i].eb(res);
			adj[res].eb(i);
			res++;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
		if (!vs[i]) {
			res++;
			dfs(i);
		}
	}
	printf("%d\n", res);
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}

