// https://codeforces.com/group/FLVn1Sc504/contest/274825/problem/O
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back

using namespace std;

struct node {
	node* a[26];
	int cnt;
	node() {
		memset(a, 0, sizeof(a));
		cnt = 0;
	}
};

const int mm = 300002;
const ll mod = 1337377;

string s;
int n, m;
node* root = new node();
ll f[mm];

void add(string &s) {
	node *p = root;
	for (char x: s) {
		int c = x - 'a';
		if (!p->a[c]) {
			p->a[c] = new node();
		}
		p = p->a[c];
	}
	p->cnt++;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> n;
	for (int i = 1; i <= n; ++i) {
		string tmp;
		cin >> tmp;
		add(tmp);
	}
	m = s.length();
	f[m] = 1;
	for (int i = m - 1; i >= 0; --i) {
		node* p = root;
		f[i] = 0;
		for (int j = i; j < m; ++j) {
			int c = s[j] - 'a';
			if (!p->a[c]) {
				break;
			}
			p = p->a[c];
			f[i] = (f[i] + f[j + 1] * p->cnt) % mod;
		}
	}
	cout << f[0] << "\n";
}

