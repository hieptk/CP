// https://atcoder.jp/contests/abc177/tasks/abc177_e
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 1000002;

int n, a[nm];
int np;
ll p[nm];
bool mark[nm];
int used[nm];

void get_primes() {
	np = 1;
	p[1] = 2;
	for (ll i = 3; i < nm; i += 2) {
		if (!mark[i]) {
			p[++np] = i;
			for (ll j = i * i; j < nm; j += 2ll * i) {
				mark[j] = 1;
			}
		}
	}
}

void factorize(int n) {
	for (int j = 1; j <= np && p[j] * p[j] <= n; ++j) {
		ll i = p[j];
		if (n % i == 0) {
			used[i]++;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n > 1) {
		used[n]++;
	}
}

bool check_pairwise() {
	for (int i = 2; i < nm; ++i) {
		if (used[i] > 1) {
			return 0;
		}
	}
	return 1;
}

bool check_setwise() {
	for (int i = 2; i < nm; ++i) {
		if (used[i] == n) {
			return 0;
		}
	}
	return 1;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	get_primes();
	cin >> n;
//	n = 1000000;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
//		a[i] = 999983;
		factorize(a[i]);
	}

	if (check_pairwise()) {
		cout << "pairwise coprime\n";
		return 0;
	}
	if (check_setwise()) {
		cout << "setwise coprime\n";
		return 0;
	}
	cout << "not coprime\n";
#ifdef LOCAL
	cout << (double) clock() / CLOCKS_PER_SEC << "\n";
#endif
}

