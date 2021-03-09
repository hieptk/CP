// https://codeforces.com/contest/1493/problem/C
#include <bits/stdc++.h>

using namespace std;

int n, k;
string s;
int cnt[26];

void solve() {
	cin >> n >> k >> s;
	if (n % k) {
		cout << "-1\n";
		return;
	}
	memset(cnt, 0, sizeof(cnt));

	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
	}
	bool ok = 1;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % k) {
			ok = 0;
			break;
		}
	}
	if (ok) {
		cout << s << "\n";
		return;
	}
	for (int i = n - 1; i >= 0; --i) {
		cnt[s[i] - 'a']--;
		int sum = 0;
		for (int j = 0; j < 26; ++j) {
			if (cnt[j] % k) {
				sum += k - cnt[j] % k;
			}
		}
		for (int j = s[i] - 'a' + 1; j < 26; ++j) {
			if (cnt[j] % k) {
				sum -= k - cnt[j] % k;
			}
			cnt[j]++;
			if (cnt[j] % k) {
				sum += k - cnt[j] % k;
			}
			if (sum <= n - i - 1) {
				for (int j2 = 0; j2 < 26; ++j2) {
					if (cnt[j2] % k) {
						cnt[j2] = k - cnt[j2] % k;
					} else {
						cnt[j2] = 0;
					}
				}
				cnt[0] += n - i - 1 - sum;
				int j2 = 0;
				for (int u = i + 1; u < n; ++u) {
					while (!cnt[j2]) {
						j2++;
					}
					s[u] = char(j2 + 'a');
					cnt[j2]--;
				}
				s[i] = char(j + 'a');
				cout << s << "\n";
				return;
			}
			if (cnt[j] % k) {
				sum -= k - cnt[j] % k;
			}
			cnt[j]--;
			if (cnt[j] % k) {
				sum += k - cnt[j] % k;
			}
		}
	}
	cout << "-1\n";
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
