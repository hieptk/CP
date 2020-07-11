// https://atcoder.jp/contests/aising2020/tasks/aising2020_e
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 200002;

struct rec {
	int k;
	ll l, r;
};

int n;
rec a[nm];
int nb, nc;
rec b[nm], c[nm];

bool cmp(rec &a, rec &b) {
	if (a.k != b.k) {
		return a.k < b.k;
	}
	return a.l - a.r > b.l - b.r;
}

bool cmp2(rec &a, rec &b) {
	if (a.k != b.k) {
		return a.k > b.k;
	}
	return a.r - a.l > b.r - b.l;
}

void solve() {
	scanf("%d", &n);
	ll res = 0;
	nb = nc = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%lld%lld", &a[i].k, &a[i].l, &a[i].r);
		if (a[i].l > a[i].r) {
			b[++nb] = a[i];
		} else if (a[i].l < a[i].r) {
			c[++nc] = a[i];
		} else {
			res += a[i].l;
		}
	}
	sort(b + 1, b + nb + 1, cmp);
	priority_queue<ll, vector<ll>, greater<ll>> cur;
	for (int i = 1; i <= nb; ++i) {
		if (cur.size() + 1 <= b[i].k) {
			res += b[i].l;
			cur.emplace(b[i].l - b[i].r);
		} else if (cur.size() == b[i].k && b[i].l - b[i].r > cur.top()) {
			res = res - cur.top() + b[i].l;
			cur.pop();
			cur.emplace(b[i].l - b[i].r);
		} else {
			res += b[i].r;
		}
	}
	sort(c + 1, c + nc + 1, cmp2);
	priority_queue<ll, vector<ll>, greater<ll>> cur2;
	for (int i = 1; i <= nc; ++i) {
		if (n - cur2.size() > c[i].k) {
			res += c[i].r;
			cur2.emplace(c[i].r - c[i].l);
		} else if (cur2.size() && n - cur2.size() == c[i].k && c[i].r - c[i].l > cur2.top()) {
			res = res - cur2.top() + c[i].r;
			cur2.pop();
			cur2.emplace(c[i].r - c[i].l);
		} else {
			res += c[i].l;
		}
	}
	printf("%lld\n", res);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}

