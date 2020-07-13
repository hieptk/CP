// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2112
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second
#define ull __int128

using namespace std;

const int id[] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};

struct node {
	node* a[10];
	unordered_map<string, int> pos;
	node() {
		memset(a, 0, sizeof(a));
	}

	void add(string &s, int i) {
		if (i == s.length()) {
			pos[s] = pos.size();
			return;
		}
		int x = id[s[i] - 'a'];
		if (!a[x]) {
			a[x] = new node();
		}
		a[x]->add(s, i + 1);
	}
};

const int mm = 250002;
const int inf = 1e9;

int n;
int f[mm], trace[mm];

string calc(string &s, node* root) {
	int m = s.length();
	f[m] = 0;
	for (int i = m - 1; i >= 0; --i) {
		node* p = root;
		f[i] = inf;
		trace[i] = -1;
		string tmp;
		for (int j = i; j < m; ++j) {
			int x = id[s[j] - 'a'];
			if (!p->a[x]) {
				break;
			}
			p = p->a[x];
			tmp += s[j];
			if (p->pos.count(tmp)) {
				int k = p->pos[tmp];
				k = min(k, (int) p->pos.size() - k);
				int newf = f[j + 1] + j - i + 1 + k + (j < m - 1);
				if (newf < f[i]) {
					f[i] = newf;
					trace[i] = j;
				}
			}
		}
	}

	string res;
	for (int i = 0; i < m; ) {
		node* p = root;
		string tmp;
		int j;
		for (j = i; j <= trace[i]; ++j) {
			int x = id[s[j] - 'a'];
			p = p->a[x];
			tmp += s[j];
			res += char(id[s[j] - 'a'] + '0');
		}
		int k = p->pos[tmp];
		if (!k) {

		} else if (k < (int) p->pos.size() - k) {
			res += "U(" + to_string(k) + ")";
		} else {
			res += "D(" + to_string((int) p->pos.size() - k) + ")";
		}
		if (j < m) {
			res += 'R';
		}
		i = j;
	}
	return res;
}

void solve() {
	node root;
	for (int i = 1; i <= n; ++i) {
		string s;
		cin >> s;
		root.add(s, 0);
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; ++i) {
		string s;
		cin >> s;
		cout << calc(s, &root) << "\n";
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	do {
		cin >> n;
		if (!n) {
			break;
		}
		solve();
	} while (1);
}

