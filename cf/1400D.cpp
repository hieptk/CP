// https://codeforces.com/contest/1400/problem/D
#include <bits/stdc++.h>

#define fi first
#define se second
#define eb emplace_back

typedef long long ll;

using namespace std;

const int nm = 3002;

int n, a[nm];
int cnt0[nm], cnt[nm];

void solve() {
	cin >> n;
	memset(cnt0, 0, sizeof(cnt0));
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		cnt0[a[i]]++;
	}
	ll res = 0;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i + 3 <= n; ++i) {
		cnt0[a[i]]--;
		int s = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int k = i + 2; k + 1 <= n; ++k) {
			int x = a[k - 1];
			if (a[k] == x) {
				s -= cnt[x] * (cnt0[x] - cnt[x] - 1);
				cnt[x]++;
				s += cnt[x] * (cnt0[x] - cnt[x] - 1);
			} else {
				int y = a[k];
				s -= cnt[x] * (cnt0[x] - cnt[x] - 1);
				s -= cnt[y] * (cnt0[y] - cnt[y]);
				cnt[x]++;
				s += cnt[x] * (cnt0[x] - cnt[x]);
				s += cnt[y] * (cnt0[y] - cnt[y] - 1);
			}
			if (a[i] == a[k]) {
				res += s;
			}
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
    	solve();
    }
}

