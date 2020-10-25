// https://codeforces.com/contest/1400/problem/E
#include <bits/stdc++.h>

#define fi first
#define se second
#define eb emplace_back

typedef long long ll;

using namespace std;

const int nm = 5002;

int n, a[nm];

ll calc(int l, int r, int x) {
	int y = a[l];
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] < y) {
			y = a[i];
		}
	}
	ll tmp = y - x;
	for (int i = l; i <= r && tmp < r - l + 1; ) {
		if (a[i] <= y) {
			i++;
			continue;
		}
		int j = i;
		while (j + 1 <= r && a[j + 1] > y) {
			j++;
		}
		tmp += calc(i, j, y);
		i = j + 1;
	}
	return min(tmp, (ll) r - l + 1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
    	cin >> a[i];
    }
    cout << calc(1, n, 0) << "\n";
}

