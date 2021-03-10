// https://codeforces.com/contest/1493/problem/D
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const int nm = 200002;
const int mod = 1000000007;

int np;
ll primes[nm];
bool notprime[nm];
unordered_map<int, int> cnt[nm];
set<pair<int, int>> freqs[nm];
int n, m;
ll a[nm];
ll res;

void find_primes() {
	notprime[0] = notprime[1] = 1;
	for (ll i = 2; i < nm; ++i) {
		if (!notprime[i]) {
			primes[++np] = i;
			for (ll j = i * i; j < nm; j += i * 2) {
				notprime[j] = 1;
			}
		}
	}
}

void add(int p, int id, int x) {
	int f = cnt[p][id];
	cnt[p][id] = f + x;

	int cur_min = freqs[p].size() == n ? freqs[p].begin()->first : 0;
	freqs[p].erase({f, id});
	freqs[p].insert({f + x, id});
	int new_min = freqs[p].size() == n ? freqs[p].begin()->first : 0;
	for (int j = 1; j <= new_min - cur_min; ++j) {
		res = (res * p) % mod;
	}
}

void factorize(int id, int x) {
	for (int i = 1; i <= np && primes[i] * primes[i] <= x; ++i) {
		int tmp = 0;
		while (x % primes[i] == 0) {
			tmp++;
			x /= primes[i];
		}
		if (tmp) {
			add(primes[i], id, tmp);
		}
	}
	if (x > 1) {
		add(x, id, 1);
	}
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	find_primes();
	cin >> n >> m;
	res = 1;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		factorize(i, a[i]);
	}
	for (int i = 1; i <= m; ++i) {
		int id, x;
		cin >> id >> x;
		factorize(id, x);
		cout << res << "\n";
	}
}

