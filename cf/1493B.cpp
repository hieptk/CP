// https://codeforces.com/contest/1493/problem/B
#include <bits/stdc++.h>

using namespace std;

int h, m, hh, mm;

int rev[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

bool ok(int hh, int mm) {
	int a = rev[hh / 10], b = rev[hh % 10], c = rev[mm /10], d = rev[mm % 10];
	return a >= 0 && b >= 0 && c >= 0 && d >= 0 && d * 10 + c < h && b * 10 + a < m;
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		scanf("%d%d%d:%d", &h, &m, &hh, &mm);
		while (!ok(hh, mm)) {
			if (mm == m - 1) {
				if (hh == h - 1) {
					hh = mm = 0;
				} else {
					hh++;
					mm = 0;
				}
			} else {
				mm++;
			}
		}
		printf("%02d:%02d\n", hh, mm);
	}
}
