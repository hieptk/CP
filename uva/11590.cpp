// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2637
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define ull __int128

using namespace std;

int n, m;

struct node {
	node* a[2];
	ull cnt, sum;
	node() {
		a[0] = a[1] = 0;
		cnt = sum = 0;
	}

	void add(string &s, int i) {
		if (i + 1 == s.length()) {
			cnt = 1;
			return;
		}
		int x = s[i] - '0';
		if (!a[x]) {
			a[x] = new node();
		}
		a[x]->add(s, i + 1);
	}

	void build(int d) {
		sum = 0;
		if (a[0]) {
			a[0]->build(d + 1);
			sum += a[0]->sum;
		}
		if (a[1]) {
			a[1]->build(d + 1);
			sum += a[1]->sum;
		}
		if (cnt) {
			cnt = (((ull) 1) << (m - d)) - sum;
			sum = (((ull) 1) << (m - d));
//			cout << m << " " << d << " " << cnt << " " << sum << "\n";
		}
	}

	ull count(string &s, int i) {
		if (i + 1 == s.length()) {
			return cnt;
		}
		int x = s[i] - '0';
		if (!a[x]) {
			return 0;
		}
		return a[x]->count(s, i + 1);
	}
};

void solve() {
	node root;
	root.cnt = 1;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		root.add(s, 0);
	}
	root.build(0);
	int k;
	cin >> k;
	for (int i = 1; i <= k; ++i) {
		string s;
		cin >> s;
		cout << (unsigned long long) root.count(s, 0) << "\n";
	}
	cout << "\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	do {
		cin >> n >> m;
		if (!n) {
			break;
		}
		solve();
	} while (1);
}

