// https://codeforces.com/contest/1370/problem/B
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;

int n;
pair<int, int> a[2 * nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; ++i) {
			scanf("%d", &a[i].fi);
			a[i].fi &= 1;
			a[i].se = i;
		}
		sort(a + 1, a + 2 * n + 1);
		int cnt = 0;
		for (int i = 1; i < 2 * n; i += 2) {
			if (a[i].fi != a[i + 1].fi) {
				continue;
			}
			printf("%d %d\n", a[i].se, a[i + 1].se);
			cnt++;
			if (cnt == n - 1) {
				break;
			}
		}
	}
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}
