// https://atcoder.jp/contests/agc044/tasks/agc044_b
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back

using namespace std;

const int nm = 502;
const int x[] = {-1, 0, 0, 1};
const int y[] = {0, -1, 1, 0};

int n;
int a[nm * nm];
int b[nm][nm];
int c[nm][nm];

void bfs(int u, int v) {
//	cout << u << " " << v << " " << b[u][v] << "\n";
	queue<pair<int, int>> q;
	q.emplace(u, v);
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int i2 = i + x[k], j2 = j + y[k];
			if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n && b[i2][j2] > b[i][j] + 1 - c[i][j]) {
				b[i2][j2] = b[i][j] + 1 - c[i][j];
//				cout << i2 << " " << j2 << " " << b[i2][j2] << "\n";
				q.emplace(i2, j2);
			}
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n * n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			b[i][j] = min(i - 1, n - i);
			b[i][j] = min(b[i][j], min(j - 1, n - j));
		}
	}

	int res = 0;
	for (int i = 1; i <= n * n; ++i) {
		int u = (a[i] - 1) / n + 1, v = (a[i] - 1) % n + 1;
		res += b[u][v];
		c[u][v] = 1;
		bfs(u, v);
	}

	printf("%d\n", res);
}


