// https://atcoder.jp/contests/aising2020/tasks/aising2020_d
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;

int n;
string s;
ll powmod[nm][2];

ll f(ll n) {
	if (!n) {
		return 0;
	}
	return f(n % __builtin_popcount(n)) + 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += s[i] - '0';
	}
	if (cnt == 0) {
		for (int i = 0; i < n; ++i) {
			cout << "1\n";
		}
		return 0;
	}
	if (cnt == 1) {
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') {
				s[i] = '1';
				if (s[n - 1] == '0') {
					cout << "1\n";
				} else {
					cout << "2\n";
				}
				s[i] = '0';
			} else {
				cout << "0\n";
			}
		}
		return 0;
	}
	powmod[0][0] = 1 % (cnt - 1);
	powmod[0][1] = 1 % (cnt + 1);
	for (int i = 1; i <= n; ++i) {
		powmod[i][0] = (powmod[i - 1][0] * 2) % (cnt - 1);
		powmod[i][1] = (powmod[i - 1][1] * 2) % (cnt + 1);
	}
	ll mod0 = 0, mod1 = 0;
	for (int i = 0; i < n; ++i) {
		mod0 = (mod0 * 2 + s[i] - '0') % (cnt - 1);
		mod1 = (mod1 * 2 + s[i] - '0') % (cnt + 1);
	}
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			ll newmod = (mod1 + powmod[n - 1 - i][1]) % (cnt + 1);
			cout << f(newmod) + 1 << "\n";
		} else {
			ll newmod = (mod0 - powmod[n - 1 - i][0] + cnt - 1) % (cnt - 1);
			cout << f(newmod) + 1 << "\n";
		}
	}
}

