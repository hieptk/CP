// https://codeforces.com/contest/1521/problem/C
#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const int nm = 10002;

int n, a[nm];

void solve(int test) {
	cin >> n;

	int posn = -1, posn1 = -1;
	for (int i = 1; i < n; i += 2) {
		cout << "? 1 " << i << " " << i + 1 << " " << n - 1 << "\n";
		cout.flush();
		int ret;
		cin >> ret;
		if (ret == n) {
			posn = i + 1;
			break;
		} else if (ret == n - 1) {
			if (posn1 == -1) {
				cout << "? 1 " << i + 1 << " " << i << " " << n - 1 << "\n";
				cout.flush();
				cin >> ret;
				if (ret == n) {
					posn = i;
					break;
				}
				posn1 = i; // or i + 1
			} else {
				posn = i;
				break;
			}
		}
	}

	if (posn == -1) {
		posn = n;
	}

	for (int i = 1; i <= n; ++i) {
		if (i == posn) {
			a[i] = n;
			continue;
		}
		cout << "? 2 " << i << " " << posn << " 1\n";
		cout.flush();
		cin >> a[i];
	}

	cout << "!";
	for (int i = 1; i <= n; ++i) {
		cout << " " << a[i];
	}
	cout << "\n";
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	auto begin = clock();
#endif
//	ios::sync_with_stdio(0);
//	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		solve(i);
	}
#ifdef LOCAL
	cout << (ld) (clock() - begin) / CLOCKS_PER_SEC << "\n";
#endif
}
