// https://www.spoj.com/problems/KQUERY/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 30002;
const int mm = 200002;

struct query {
	int u, v, k, id;
};

int n;
pair<int, int> a[nm];
int m;
query q[mm];
int tree[nm];
int res[mm];

bool cmp(query &a, query &b) {
	return a.k > b.k;
}

void add(int i) {
	while (i <= n) {
		tree[i]++;
		i += i & (-i);
	}
}

int get(int i) {
	int res = 0;
	while (i > 0) {
		res += tree[i];
		i -= i & (-i);
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].fi);
		a[i].se = i;
	}
	sort(a + 1, a + n + 1, greater<pair<int, int>>());
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i) {
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		q[i] = {u, v, k, i};
	}
	sort(q + 1, q + m + 1, cmp);
	for (int i = 1, j = 1; i <= m; ++i) {
		while (j <= n && a[j].fi > q[i].k) {
			add(a[j].se);
			j++;
		}
		res[q[i].id] = get(q[i].v) - get(q[i].u - 1);
	}
	for (int i = 1; i <= m; ++i) {
		printf("%d\n", res[i]);
	}
}

