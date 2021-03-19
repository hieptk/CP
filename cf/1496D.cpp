// https://codeforces.com/contest/1496/problem/D
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 100002;

int n, a[nm];
int nb, b[nm], maxb;
int nc, c[nm], maxc;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	maxb = -1;
	for (int i = 1; i <= n; ) {
		int j = i;
		while (j + 1 <= n && a[j + 1] > a[j]) {
			j++;
		}
		if (j - i > maxb) {
			maxb = j - i;
			nb = 1;
			b[1] = j;
		} else if (j - i == maxb) {
			b[++nb] = j;
		}
		i = j + 1;
	}
	maxc = -1;
	for (int i = 1; i <= n; ) {
		int j = i;
		while (j + 1 <= n && a[j + 1] < a[j]) {
			j++;
		}
		if (j - i > maxc) {
			maxc = j - i;
			nc = 1;
			c[1] = i;
		} else if (j - i == maxc) {
			c[++nc] = i;
		}
		i = j + 1;
	}

	if (maxb < maxc) {
		maxb = maxc;
		nb = nc;
		for (int i = 1; i <= nb; ++i) {
			b[i] = c[i];
		}
	} else if (maxb == maxc) {
		for (int i = 1; i <= nc; ++i) {
			b[++nb] = c[i];
		}
	}

	if (nb == 2 && b[1] == b[2] && maxb % 2 == 0) {
		cout << "1\n";
	} else {
		cout << "0\n";
	}
}

