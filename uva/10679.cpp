// https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1620
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

struct Node {
	int val;
	Node* next = 0;
	Node(int val): val(val) {}
};

struct List {
	Node *head = 0, *tail = 0;
	int len = 0;

	void add(int key) {
		if (!head) {
			head = tail = new Node(key);
			len = 1;
		} else {
			tail->next = new Node(key);
			tail = tail->next;
			len++;
		}
	}

	void join(List &other) {
		if (!other.head) {
			return;
		}
		if (!head) {
			head = other.head;
			tail = other.tail;
			len = other.len;
			return;
		}
		tail->next = other.head;
		tail = other.tail;
		len += other.len;
	}
};

bool found[1002];

struct ACTrie {

    unordered_map<char, ACTrie*> edges;
    ACTrie* lsp = 0;
    List matches;

    void insert(string &t, int key, int i = 0) {
        if (i == t.length()) {
        	matches.add(key);
            return;
        }
        if (edges.count(t[i]) == 0)
            edges[t[i]] = new ACTrie;
        edges[t[i]]->insert(t, key, i+1);
    }

    void search(string &s, int i = 0, bool print = true) {
        if (print) {
//        	cout << matches.len << " matches ending at " << i-1 << "\n";
        	for (Node* p = matches.head; p; p = p->next) {
        		found[p->val] = 1;
        	}
        }

        if (i == s.length()) return;

        if (!edges.count(s[i])) {
            if (!lsp) search(s, i+1, true);
            else lsp->search(s, i, false);
        } else {
            edges[s[i]]->search(s, i+1, true);
        }
    }
};

void preprocess(ACTrie &root) {
    queue<ACTrie*> q;
    root.lsp = 0; q.push(&root);
    while (!q.empty()) {
        ACTrie *u = q.front(); q.pop();
        for (auto &it : u->edges) {
            char c = it.first; ACTrie *v = it.second;

            ACTrie *l = u->lsp;
            while (l && !l->edges.count(c))
                l = l->lsp;
            if (!l) {
                v->lsp = &root;
            } else {
                v->lsp = l->edges[c];
                v->matches.join(v->lsp->matches);
            }
            q.push(v);
        }
    }
}

string s;
int n;

void solve() {
	cin >> s >> n;
	ACTrie root;
	for (int i = 1; i <= n; ++i) {
		string t;
		cin >> t;
		root.insert(t, i);
	}
	preprocess(root);
	memset(found, 0, sizeof(found));
	root.search(s);
	for (int i = 1; i <= n; ++i) {
		if (found[i]) {
			cout << "y\n";
		} else {
			cout << "n\n";
		}
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

