// https://codeforces.com/contest/1363/problem/C
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1002;

int n, x;
int deg[nm];

void solve() {
	scanf("%d%d", &n, &x);
	memset(deg, 0, sizeof(deg));
	for (int i = 1; i< n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++;
		deg[v]++;
	}
	if (deg[x] <= 1 || n % 2 == 0) {
		printf("Ayush\n");
	} else {
		printf("Ashish\n");
	}
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
}
