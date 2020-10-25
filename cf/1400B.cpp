// https://codeforces.com/contest/1400/problem/B
#include <bits/stdc++.h>

#define eb emplace_back
#define ld long double
#define ll long long

using namespace std;

const int nm = 200002;
const ll inf = 1e12;

ll p, f;
ll cnt1, cnt2, w1, w2;

void solve(int test) {
	cin >> p >> f >> cnt1 >> cnt2 >> w1 >> w2;
	if (w1 > w2) {
		swap(w1, w2);
		swap(cnt1, cnt2);
	}
	ll res = 0;
	for (ll i = 0; i <= cnt1; ++i) {
		if (i * w1 <= f) {
			ll cnt11 = cnt1 - i;
			ll j = min((f - i * w1) / w2, cnt2);
			ll cnt22 = cnt2 - j;
			ll ii = min(p / w1, cnt11);
			ll jj = min((p - ii * w1) / w2, cnt22);
			res = max(res, i + j + ii + jj);
		} else {
			break;
		}
	}
	cout << res << "\n";
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
