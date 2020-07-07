// https://www.spoj.com/problems/NAJPF/
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1000002;

int n, m;
char s[nm], t[nm];
int f[nm];

void solve() {
	scanf("%s%s", t, s);
	n = strlen(s);
	m = strlen(t);
	f[0] = -1;
	int j = 0;
	for (int i = 1; i < n; ) {
		if (s[i] == s[j]) {
			f[i++] = ++j;
		} else if (j) {
			j = f[j - 1];
		} else {
			f[i++] = 0;
		}
	}
	vector<int> res;
	j = 0;
	for (int i = 0; i < m; ) {
		if (t[i] == s[j]) {
			if (j == n - 1) {
				res.eb(i - n + 2);
				j = f[j];
			} else {
				j++;
			}
			i++;
		} else if (j) {
			j = f[j - 1];
		} else {
			i++;
		}
	}
	if (!res.size()) {
		printf("Not Found\n");
		return;
	}
	printf("%d\n", res.size());
	for (int i = 0; i + 1 < res.size(); ++i) {
		printf("%d ", res[i]);
	}
	printf("%d\n", res.back());
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
		if (t) {
			printf("\n");
		}
	}
}

