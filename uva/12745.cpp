// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4598
#include <bits/stdc++.h>

#define fi first
#define se second
#define eb emplace_back

#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)
#define Fit(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define Fitd(i,v) for(__typeof((v).rbegin()) i = (v).rbegin(); i != (v).rend(); ++i)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))

typedef long long ll;

using namespace std;

const int maxv = 200002;

namespace twosat {
	int n;
	vector<int> forward[maxv], backward[maxv];
	bool used[maxv];
	int cnt, order[maxv], comp[maxv];

	void init(int _n) {
		n = _n;
		Rep(i, n) {
			forward[i].clear();
			backward[i].clear();
		}
	}

	void add(int u, int v) {
		forward[u].pb(v);
		backward[v].pb(u);
	}

	void dfs1(int u) {
		used[u] = true;
		Rep(i, sz(forward[u])) {
			int v = forward[u][i];
			if (!used[v]) dfs1(v);
		}
		order[cnt++] = u;
	}

	void dfs2(int u, int c) {
		comp[u] = c;
		Rep(i, sz(backward[u])) {
			int v = backward[u][i];
			if (comp[v] == -1) dfs2(v, c);
		}
	}

	bool solve(vector<int> &ret) {
		cnt = 0;
		ms(used, false);
		Rep(u, n) if (!used[u]) dfs1(u);

		ms(comp, -1);
		int c = 0;
		Repd(i, n) {
			int u = order[i];
			if (comp[u] == -1) dfs2(u, c++);
		}

		for (int u = 0; u < n; u += 2)
			if (comp[u] == comp[u ^ 1]) return false;

		ret.clear();
		for (int u = 0; u < n; u += 2) {
			int choose = (comp[u] > comp[u ^ 1]) ? u : u ^ 1;
			if (!(choose & 1)) ret.pb(choose >> 1);
		}
		return true;
	}
}

int n, m;

void solve(int test) {
	cout << "Case " << test << ": ";
	cin >> n >> m;
	twosat::init(2 * n);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		int uu = u > 0 ? 2 * (u - 1) : 2 * (-u - 1) + 1;
		int vv = v > 0 ? 2 * (v - 1) : 2 * (-v - 1) + 1;
		twosat::add(uu, vv ^ 1);
		twosat::add(vv, uu ^ 1);
	}
	vector<int> res;
	if (twosat::solve(res)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
    	solve(i);
    }
}

