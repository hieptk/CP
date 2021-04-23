// https://atcoder.jp/contests/jsc2021/tasks/jsc2021_e
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;

const int nm = 500002;

int k, l;
string s;
int orig[nm][26], extra[nm][26];

void add(int i, int n, char x, int iter) {
	if (n == l) {
		orig[i][x - 'a']++;
		return;
	}
	if (2 * i - 1 == n) {
		extra[iter][x - 'a']++;
		return;
	}
	if (i <= n / 2) {
		add(i, n / 2, x, iter + 1);
	} else {
		add(n + 1 - i, n / 2, x, iter + 1);
	}
}

bool palin(string &s) {
	for (int i = 0, j = (int) s.length() - 1; i < j; ++i, --j) {
		if (s[i] != s[j]) {
			return 0;
		}
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> s;
	int n = s.length();
	if (k > 20 || (n << 1) < (1 << k)) {
		cout << "impossible\n";
		return 0;
	}
	l = n >> k;
	if (!l) {
		l = 1;
		for (int i = 1; i <= n; ++i) {
			add(i, n, s[i - 1], 0);
		}
		int res = 0;
		for (int i = 0; i <= k; ++i) {
			int sum = 0, cmax = 0;
			for (int j = 0; j < 26; ++j) {
				sum += extra[i][j];
				cmax = max(cmax, extra[i][j]);
			}
			res += sum - cmax;
		}
		for (int i = 1; i <= l; ++i) {
			int sum = 0, cmax = -1, jmax = 0;
			for (int j = 0; j < 26; ++j) {
				sum += orig[i][j];
				if (orig[i][j] > cmax) {
					cmax = orig[i][j];
					jmax = j;
				}
			}
			res += sum - cmax;
		}
		cout << res << "\n";

		return 0;
	}
	if (l == 1) {
		cout << "impossible\n";
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		add(i, n, s[i - 1], 0);
	}

	int res = 0;
	for (int i = 0; i <= k; ++i) {
		int sum = 0, cmax = 0;
		for (int j = 0; j < 26; ++j) {
			sum += extra[i][j];
			cmax = max(cmax, extra[i][j]);
		}
		res += sum - cmax;
	}

	string firstl;
	for (int i = 1; i <= l; ++i) {
		int sum = 0, cmax = -1, jmax = 0;
		for (int j = 0; j < 26; ++j) {
			sum += orig[i][j];
			if (orig[i][j] > cmax) {
				cmax = orig[i][j];
				jmax = j;
			}
		}
		res += sum - cmax;
		firstl += char(jmax + 'a');
	}

	if (!palin(firstl)) {
		cout << res << "\n";
		return 0;
	}

	int res2 = 1e9;
	for (int i = 1; i <= l; ++i) {
		if (2 * i - 1 == l) {
			continue;
		}
		int cmax = -1, cmax2 = -1;
		for (int j = 0; j < 26; ++j) {
			if (orig[i][j] > cmax) {
				cmax2 = cmax;
				cmax = orig[i][j];
			} else if (orig[i][j] > cmax2) {
				cmax2 = orig[i][j];
			}
		}
		res2 = min(res2, res + cmax - cmax2);
	}
	cout << res2 << "\n";
}

