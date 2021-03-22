// https://atcoder.jp/contests/abc196/tasks/abc196_b
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

using namespace std;


int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	for (char x: s) {
		if (x == '.') {
			break;
		}
		cout << x;
	}
}

