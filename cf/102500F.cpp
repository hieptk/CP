// https://codeforces.com/gym/102500/problem/F
#include <bits/stdc++.h>

#define eb emplace_back

using namespace std;

const int nm = 200002;

int n;
vector<int> adj[nm];
unordered_map<int, vector<int>> adj2;
bool vs[nm];
unordered_set<int> vs2;
vector<tuple<int, int, int>> res;

void dfs(int, int, int);

void dfs2(int i, int p) {
	vs2.insert(i);
	for (int j: adj2[i]) {
		if (!vs[j]) {
			dfs(j, p, i);
		}
	}
}

void dfs(int i, int p, int p2) {
	vs[i] = 1;
	if (p != -1) {
		res.eb(p, i, p2);
	}
	for (int j: adj[i]) {
		if (!vs2.count(j)) {
			dfs2(j, i);
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			adj[i].eb(x);
			adj2[x].eb(i);
		}
	}
	dfs(1, -1, -1);
	if (res.size() == n - 1) {
		for (auto &t: res) {
			int i, j, k;
			tie(i, j, k) = t;
			cout << i << " " << j << " " << k << "\n";
		}
	} else {
		cout << "impossible\n";
	}
}

