// https://atcoder.jp/contests/abc196/tasks/abc196_d
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

int h, w, a, b;
ll res;
int c[25][25];

void doit(int i, int j, int a, int b) {
	if (!a) {
		res++;
		return;
	}
	if (c[i][j]) {
		if (j == w - 1) {
			doit(i + 1, 0, a, b);
		} else {
			doit(i, j + 1, a, b);
		}
		return;
	}
	if (j + 1 < w &&!c[i][j + 1]) {
		c[i][j] = c[i][j + 1] = 1;
		doit(i, j + 1, a - 1, b);
		c[i][j] = c[i][j + 1] = 0;
	}
	if (i + 1 < h && !c[i + 1][j]) {
		c[i][j] = c[i + 1][j] = 1;
		if (j == w - 1) {
			doit(i + 1, 0, a - 1, b);
		} else {
			doit(i, j + 1, a - 1, b);
		}
		c[i][j] = c[i + 1][j] = 0;
	}
	if (b) {
		c[i][j] = 1;
		if (j == w - 1) {
			doit(i + 1, 0, a, b - 1);
		} else {
			doit(i, j + 1, a, b - 1);
		}
		c[i][j] = 0;
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> h >> w >> a >> b;
	doit(0, 0, a, b);
	cout << res << "\n";
}

