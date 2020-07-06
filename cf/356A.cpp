// https://codeforces.com/contest/356/problem/A
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 300002;

int n, m;
int nnext[nm], res[nm];

int getNext(int i) {
	if (nnext[i] == i) {
		return i;
	}
	return nnext[i] = getNext(nnext[i]);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 1; ++i) {
		nnext[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		int j = getNext(u);
		while (j <= v) {
			if (j != x) {
				res[j] = x;
				nnext[j] = j + 1;
			}
			j = getNext(j + 1);
		}
	}
	for (int i = 1; i <= n; ++i) {
		printf("%d ", res[i]);
	}
}

