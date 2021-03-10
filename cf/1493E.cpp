// https://codeforces.com/contest/1493/problem/E
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
string l, r;

void add(string &s) {
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == '0') {
			s[i]++;
			return;
		} else {
			s[i] = '0';
		}
	}
	s = "1" + s;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r;
	if (l[0] != r[0]) {
		for (int i = 1; i <= n; ++i) {
			cout << "1";
		}
		cout << "\n";
		return 0;
	}
	if (r[n - 1] == '1') {
		cout << r << "\n";
		return 0;
	}
	if (l == r) {
		cout << r << "\n";
		return 0;
	}
	add(l);
	if (l == r) {
		cout << r << "\n";
		return 0;
	}
	add(r);
	cout << r << "\n";
}

