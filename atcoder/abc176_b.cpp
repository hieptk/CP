// https://atcoder.jp/contests/abc176/tasks/abc176_b
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int sum = 0;
	for (char x: s) {
		sum += x - '0';
	}
	cout << (sum % 9 == 0 ? "Yes\n" : "No\n");
}

