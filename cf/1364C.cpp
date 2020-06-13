// https://codeforces.com/contest/1364/problem/C
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;

int n, a[nm];
set<int> must;
int b[nm];

bool check() {
	int j = 0;
	set<int> x;
	for (int i = 1; i <= n; ++i) {
		x.insert(b[i]);
		while (x.count(j)) {
			j++;
		}
		if (a[i] != j) {
			return 0;
		}
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; --i) {
		if (a[i] > a[i - 1]) {
			b[i] = a[i - 1];
			for (int j = a[i - 1] + 1; j < a[i]; ++j) {
				must.insert(j);
			}
		} else {
			if (must.size()) {
				b[i] = *must.begin();
				must.erase(must.begin());
			} else {
				b[i] = n + 1;
			}
		}
	}
	if (check()) {
		for (int i = 1; i <= n; ++i) {
			printf("%d ", b[i]);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
#ifdef LOCAL
	cout << setprecision(6) << fixed << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}
