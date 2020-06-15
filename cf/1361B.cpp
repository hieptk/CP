// https://codeforces.com/contest/1361/problem/B
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 1000002;
const int mod = 1000000007;

int n, p, a[nm];
int cnt[nm];

const int bfsz = 10 << 20; char bf[bfsz + 5]; int rsz = 0;int ptr = 0;
char gc() { if (rsz <= 0) { ptr = 0; rsz = (int) fread(bf, 1, bfsz, stdin); if (rsz <= 0) return EOF; } --rsz; return bf[ptr++]; }
void ga(char &c) { c = EOF; while (!isalpha(c)) c = gc(); }
int gs(char s[]) { int l = 0; char c = gc(); while (isspace(c)) c = gc(); while (c != EOF && !isspace(c)) { s[l++] = c; c = gc(); } s[l] = '\0'; return l; }
template<class T> bool gi(T &v) {
    v = 0; char c = gc(); while (c != EOF && c != '-' && !isdigit(c)) c = gc(); if (c == EOF) return false; bool neg = c == '-'; if (neg) c = gc();
    while (isdigit(c)) { v = v * 10 + c - '0'; c = gc(); } if (neg) v = -v; return true;
}

int powmod(ll a, int n, bool usemod) {
	if (!n) {
		return 1;
	}
	ll res = powmod(a, n >> 1, usemod);
	if (res < 0) {
		return -1;
	}
	res = res * res;
	if (res >= mod) {
		if (!usemod) {
			return -1;
		}
		res %= mod;
	}
	if (n & 1) {
		res = res * a;
		if (res >= mod) {
			if (!usemod) {
				return -1;
			}
			res %= mod;
		}
	}
	return res;
}

void solve() {
//	scanf("%d%d", &n, &p);
	gi(n);
	gi(p);
	int amax = 0;
	for (int i = 1; i <= n; ++i) {
//		scanf("%d", &a[i]);
		gi(a[i]);
		cnt[a[i]]++;
		amax = max(amax, a[i]);
	}
//	int n2 = 0;
//	for (int i = 0; i <= amax; ++i) {
//		while (cnt[i]) {
//			a[++n2] = i;
//			cnt[i]--;
//		}
//	}
	if (p == 1) {
		printf("%d\n", n & 1);
		return;
	}
	sort(a + 1, a + n + 1);
	ll diff = 0;
	int unit = a[n];
	int i;
	for (i = n; i >= 1; --i) {
		if (unit > a[i]) {
//			if (diff * p^(unit - a[i]) >= i) break
			if (unit - a[i] > log(1.0 * i / diff) / log(p) - 1e-6) {
				break;
			}
			ll tmp = powmod(p, unit - a[i], 1);
//			if (tmp < 0 || diff * tmp >= i) {
//				break;
//			}
			diff *= tmp;
			unit = a[i];
		}
		diff = abs(diff - 1);
	}
	for (; i >= 1; --i) {
		if (unit > a[i]) {
			diff = (diff * powmod(p, unit - a[i], 1)) % mod;
			unit = a[i];
		}
		diff--;
		if (diff < 0) {
			diff += mod;
		}
	}

	if (unit > 0) {
		diff = (diff * powmod(p, unit, 1)) % mod;
	}
	printf("%d\n", (int) diff);
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
//	scanf("%d", &t);
	gi(t);
	while (t--) {
		solve();
	}
}
