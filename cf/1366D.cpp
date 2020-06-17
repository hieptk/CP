// https://codeforces.com/contest/1366/problem/D
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 10000002;
const int mm = 500002;

int lp[nm];
vector<int> pr;
int a[nm], b[nm];
int u[mm], v[mm];

void calc(int i) {
	int l = lp[i];
	int j = i;
	int p = 1;
	while (j > 1) {
		j /= lp[j];
		if (lp[j] > l) {
			p *= lp[j];
		}
	}
	if (p > 1 && __gcd(i, p + l) == 1) {
		a[i] = l;
		b[i] = p;
	} else {
		a[i] = b[i] = -1;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	for (int i = 2; i < nm; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.eb(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] < nm; ++j) {
			lp[i * pr[j]] = pr[j];
		}
	}
//	for (int i = 2; i < nm; ++i) {
//		calc(i);
//		if (a[i] != -1) {
//			if (i % a[i] || i % b[i] || __gcd(i, a[i] + b[i]) != 1) {
//				printf("wtf %d\n", i);
//			}
//		}
//		if (a[i] == -1) {
//			for (int j = 2; (j << 1) <= i; ++j) {
//				if (i % j == 0) {
//					for (int k = j + 1; (k << 1) <= i; ++k) {
//						if (i % k == 0 && __gcd(j + k, i) == 1) {
//							printf("wtf %d %d %d\n", i, j, k);
//							return 0;
//						}
//					}
//				}
//			}
//		}
//	}
//	return 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int x;
		scanf("%d", &x);
		if (!a[x]) {
			calc(x);
		}
		u[i] = a[x];
		v[i] = b[x];
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", u[i]);
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", v[i]);
	}
	printf("\n");
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
