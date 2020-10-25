// https://codeforces.com/gym/102500/problem/A
// http://2019.nwerc.eu/files/nwerc2019slides.pdf
#include <bits/stdc++.h>

#define fi first
#define se second
#define eb emplace_back

typedef long long ll;

using namespace std;

const int nm = 300002;
const ll inf = 1e18;

int n, w;
int score[nm];
ll sum[nm];
int lastupdate[nm];
vector<tuple<int, ll, ll>> score2sumrank[nm];

ll getsumrank(int u, int score) {
	tuple<int, ll, ll> tmp = {u, inf, inf};
	auto t = upper_bound(score2sumrank[score].begin(), score2sumrank[score].end(), tmp);
	t--;
	return get<1>(*t) + (ll) (u - get<0>(*t) + 1) * get<2>(*t);
}

ll getsumrank(int u, int v, int score) {
	ll sv = getsumrank(v, score), su = getsumrank(u - 1, score);
	return sv - su;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> w;
    for (int i = 0; i <= w; ++i) {
    	score2sumrank[i].eb(0, 0, 0);
    	score2sumrank[i].eb(1, 0, 1); // last update, prefix sum, new rank
    }
    for (int i = 1; i <= n; ++i) {
    	lastupdate[i] = 1;
    }
    for (int i = 1; i <= w; ++i) {
    	int m;
    	cin >> m;
    	while (m--) {
    		int j;
    		cin >> j;
    		int x = score[j]++;
    		sum[j] += getsumrank(lastupdate[j], i - 1, x);
    		auto last = score2sumrank[x].back();
    		score2sumrank[x].eb(i, get<1>(last) + (ll) (i - get<0>(last)) * get<2>(last), get<2>(last) + 1);
    		lastupdate[j] = i;
    	}
    }
    cout << setprecision(7) << fixed;
    for (int i = 1; i <= n; ++i) {
    	cout << (double) (sum[i] + getsumrank(lastupdate[i], w, score[i])) / w << "\n";
    }
}

