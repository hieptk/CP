// https://codeforces.com/contest/446/problem/C
#include <bits/stdc++.h>

#define ll long long
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 300002;
const ll mod = 1000000009;
const ll magic = 276601605;
const ll magic2 = 691504013;
const ll magic3 = 308495997;

int n, m;
ll a[nm];
ll tree[4 * nm];
ll add[4 * nm], add2[4 * nm];
ll powmod[nm], powmod2[nm];
ll sumpowmod[nm], sumpowmod2[nm];

void build(int l, int r, int id) {
	if (l == r) {
		tree[id] = a[l];
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	build(l, m, c1);
	build(m + 1, r, c2);
	tree[id] = (tree[c1] + tree[c2]) % mod;
}

ll calcSumPowMod(ll u1, int u, int v, ll sumpowmod[]) {
	ll res = ((sumpowmod[v] - (u > 0 ? sumpowmod[u - 1] : 0)) % mod + mod) % mod;
	return (u1 * res) % mod;
}

ll calcFibSum(int u, int v) {
	ll r1 = calcSumPowMod(magic, u, v, sumpowmod);
	ll r2 = calcSumPowMod(magic, u, v, sumpowmod2);
	return ((r1 - r2) % mod + mod) % mod;
}

void push(int l, int m, int r, int id, int c1, int c2) {
	add[c1] = (add[c1] + add[id]) % mod;
	add[c2] = (add[c2] + add[id] * powmod[m - l + 1]) % mod;
	add2[c1] = (add2[c1] + add2[id]) % mod;
	add2[c2] = (add2[c2] + add2[id] * powmod2[m - l + 1]) % mod;
	tree[c1] = ((tree[c1] + add[id] * sumpowmod[m - l] - add2[id] * sumpowmod2[m - l]) % mod + mod) % mod;
	tree[c2] = ((tree[c2] + calcSumPowMod(add[id], m - l + 1, r - l, sumpowmod)
			- calcSumPowMod(add2[id], m - l + 1, r - l, sumpowmod2)) % mod + mod) % mod;
	add[id] = add2[id] = 0;
}


void update(int u, int v, int l, int r, int id) {
	if (l >= u && r <= v) {
		ll tmp = calcFibSum(l - u + 1, r - u + 1);
		tree[id] = (tree[id] + tmp) % mod;
		add[id] = (add[id] + magic * powmod[l - u + 1]) % mod;
		add2[id] = (add2[id] + magic * powmod2[l - u + 1]) % mod;
		return;
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(l, m, r, id, c1, c2);
	if (u <= m) {
		update(u, v, l, m, c1);
	}
	if (v > m) {
		update(u, v, m + 1, r, c2);
	}
	tree[id] = (tree[c1] + tree[c2]) % mod;
}

ll get(int u, int v, int l, int r, int id) {
	if (l >= u && r <= v) {
		return tree[id];
	}
	int m = (l + r) >> 1, c1 = id << 1, c2 = c1 ^ 1;
	push(l, m, r, id, c1, c2);
	ll res = 0;
	if (u <= m) {
		res = get(u, v, l, m, c1);
	}
	if (v > m) {
		res = (res + get(u, v, m + 1, r, c2)) % mod;
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	build(1, n, 1);

	powmod[0] = powmod2[0] = sumpowmod[0] = sumpowmod2[0] = 1;
	for (int i = 1; i <= n; ++i) {
		powmod[i] = (powmod[i - 1] * magic2) % mod;
		sumpowmod[i] = (sumpowmod[i - 1] + powmod[i]) % mod;
		powmod2[i] = (powmod2[i - 1] * magic3) % mod;
		sumpowmod2[i] = (sumpowmod2[i - 1] + powmod2[i]) %mod;
	}
	for (int i = 1; i <= m; ++i) {
		int t, u, v;
		cin >> t >> u >> v;
		if (t == 1) {
			update(u, v, 1, n, 1);
		} else {
			cout << get(u, v, 1, n, 1) % mod << "\n";
		}
	}
}

