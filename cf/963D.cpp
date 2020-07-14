// https://codeforces.com/problemset/problem/963/D
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

const int nm = 100002;

deque<int> d[nm];
int res[nm];
int a[nm];
string b[nm];

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
        	if (i - 1 >= 0) {
        		for (Node* p = matches.head; p; p = p->next) {
        			int k = p->val;
        			d[k].eb(i - 1);
        			while (d[k].size() > a[k]) {
        				d[k].pop_front();
        			}
        			if (d[k].size() >= a[k]) {
        				res[k] = min(res[k], d[k].back() - d[k].front() + (int) b[k].length());
        			}
        		}
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
ACTrie root;

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i] >> b[i];
		root.insert(b[i], i);
	}
	preprocess(root);
	memset(res, 0x3f, sizeof(res));
	root.search(s);
	for (int i = 1; i <= n; ++i) {
		if (res[i] > s.length()) {
			cout << "-1\n";
		} else {
			cout << res[i] << "\n";
		}
	}
}

