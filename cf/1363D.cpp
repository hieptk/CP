// https://codeforces.com/contest/1363/problem/D
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

int n, k;
int na[nm], a[nm][nm];

void solve() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; ++i) {
		scanf("%d", &na[i]);
		for (int j = 1; j <= na[i]; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("? %d", n);
	for (int i = 1; i <= n; ++i) {
		printf(" %d", i);
	}
	printf("\n");
	fflush(stdout);
	int amax;
	scanf("%d", &amax);

	int l = 1, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		printf("? %d", mid - l + 1);
		for (int i = l; i <= mid; ++i) {
			printf(" %d", i);
		}
		printf("\n");
		fflush(stdout);
		int x;
		scanf("%d", &x);
		if (x == amax) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	int ri = -1, z = -1;
	set<int> x;
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= na[i]; ++j) {
			if (a[i][j] == l) {
				ri = i;
				break;
			}
		}
	}
	if (ri != -1) {
		for (int j = 1; j <= na[ri]; ++j) {
			x.insert(a[ri][j]);
		}
		printf("? %d", n - x.size());
		for (int i = 1; i <= n; ++i) {
			if (!x.count(i)) {
				printf(" %d", i);
			}
		}
		printf("\n");
		fflush(stdout);
		scanf("%d", &z);
	}
	printf("!");
	for (int i = 1; i <= k; ++i) {
		if (i == ri) {
			printf(" %d", z);
		} else {
			printf(" %d", amax);
		}
	}
	printf("\n");
	fflush(stdout);
	char s[100];
	scanf("%s", s);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		solve();
	}
}
