// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_b
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 1002;

int n, m, a[nm], b[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		cin >> b[i];
	}

	int i = 1, j = 1;
	while (i <= n && j <= m) {
		if (a[i] < b[j]) {
			cout << a[i++] << " ";
		} else if (a[i] > b[j]) {
			cout << b[j++] << " ";
		} else {
			i++;
			j++;
		}
	}

	while (i <= n) {
		cout << a[i++] << " ";
	}

	while (j <= m) {
		cout << b[j++] << " ";
	}
}

