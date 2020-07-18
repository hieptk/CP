// https://www.codechef.com/problems/TWOSTRS
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

struct ACTrie {

    ACTrie* edges[26];
    ACTrie* lsp = 0;
    ll sum = 0;

    ACTrie() {
    	memset(edges, 0, sizeof(edges));
    }

    void insert(string &t, ll val, int i = 0) {
        if (i == t.length()) {
        	sum += val;
            return;
        }
        if (!edges[t[i] - 'a'])
            edges[t[i] - 'a'] = new ACTrie;
        edges[t[i] - 'a']->insert(t, val, i+1);
    }

    void search(string &s, ll f[], int i = 0, bool print = true) {
        if (print) {
//        	cout << matches.len << " matches ending at " << i-1 << "\n";
        	if (i - 1 >= 0) {
        		f[i - 1] = sum;
        	}
        }

        if (i == s.length()) return;

        if (!edges[s[i] - 'a']) {
            if (!lsp) search(s, f, i+1, true);
            else lsp->search(s, f, i, false);
        } else {
            edges[s[i] - 'a']->search(s, f, i+1, true);
        }
    }

    pair<ACTrie*, bool> go(char x) {
    	if (!edges[x - 'a']) {
    		if (!lsp) return {this, false};
    		else return lsp->go(x);
    	} else {
    		return {edges[x - 'a'], true};
    	}
    }
};

void preprocess(ACTrie &root) {
    queue<ACTrie*> q;
    root.lsp = 0; q.push(&root);
    while (!q.empty()) {
        ACTrie *u = q.front(); q.pop();
        for (int c = 0; c < 26; ++c) {
            if (!u->edges[c]) {
            	continue;
            }
            auto v = u->edges[c];

            ACTrie *l = u->lsp;
            while (l && !l->edges[c])
                l = l->lsp;
            if (!l) {
                v->lsp = &root;
            } else {
                v->lsp = l->edges[c];
                v->sum += v->lsp->sum;
            }
            q.push(v);
        }
    }
}

const int nm = 10002;

string s, t;
int n;
string a[nm];
ll b[nm];
ll g[nm];

void solve(int test) {
	cin >> s >> t >> n;
	int ns = s.length(), nt = t.length();
	ACTrie root;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		root.insert(a[i], b[i]);
	}
	preprocess(root);
	root.search(t, g);
	for (int i = nt - 2; i >= 0; --i) {
		g[i] += g[i + 1];
	}

	ACTrie *p = &root;
	ll res = 0, cur = 0;
	for (int i = 0; i < ns; ++i) {
		bool print;
		tie(p, print) = p->go(s[i]);
		if (print) {
			cur += p->sum;
		}
		for (int j = 0; j < nt; ++j) {
			ll cur2 = cur;
			auto q = p;
			for (int k = j; k < j + 25 && k < nt; ++k) {
				tie(q, print) = q->go(t[k]);
				if (print) {
					cur2 += q->sum;
				}
			}
			if (j + 25 < nt) {
				cur2 += g[j + 25];
			}
			res = max(res, cur2);
		}
	}

	cout << res << "\n";
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
}

