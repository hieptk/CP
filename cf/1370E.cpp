// https://codeforces.com/contest/1370/problem/E
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1000002;

int n;
string s, t;
int f[nm];
int g[2];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	cin >> n >> s >> t;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += s[i] - '0';
		cnt -= t[i] - '0';
	}
	if (cnt) {
		printf("-1\n");
		return 0;
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) {
			continue;
		}
		int x = s[i] - '0';
		if (!g[1 - x]) {
			res++;
		} else {
			g[1 - x]--;
		}
		g[x]++;
	}
	printf("%d\n", res);
#ifdef LOCAL
	printf("%.3lf\n", (double) clock() / CLOCKS_PER_SEC);
#endif
}
