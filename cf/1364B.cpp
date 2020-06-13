// https://codeforces.com/contest/1364/problem/B
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

int n, a[nm];
int nb, b[nm];

void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	nb = 2;
	b[1] = a[1];
	b[2] = a[2];
	for (int i = 3; i <= n; ++i) {
		if ((a[i] > b[nb]) == (b[nb] > b[nb - 1])) {
			b[nb] = a[i];
		} else {
			b[++nb] = a[i];
		}
	}
	printf("%d\n", nb);
	for (int i = 1; i <= nb; ++i) {
		printf("%d ", b[i]);
	}
	printf("\n");
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		solve();
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
