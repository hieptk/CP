// https://atcoder.jp/contests/abc169/tasks/abc169_b
#include <bits/stdc++.h>

#define ll long long
#define ld long double
#define debug(x) \
	//    (cout << #x << ": " << (x) << endl)
#define eb emplace_back
#define fi first
#define se second

using namespace std;

const int nm = 100002;
const ll inf = 1000000000000000000ll;

int n;
ll a[nm];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		if (!a[i]) {
			printf("0\n");
			return 0;
		}
	}
	ll res = 1;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > inf / res) {
			printf("-1\n");
			return 0;
		}
		res *= a[i];
	}
	printf("%lld\n", res);
}

