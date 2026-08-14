#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define taskname "CPSQR"
int m, n, i, j, cnt, ans, t;
map<int, int> dem;
int main() {
	if (fopen(taskname".inp","r")) {
		freopen(taskname".inp","r",stdin);
		freopen(taskname".out","w",stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(i = 1; i <= n; i++){
		j = 2; m = i;
		t = 1;
		while(j <= sqrt(m) && m > 1){
			int cnt = 0;
			while(m % j == 0){
				m /= j;
				cnt ++;
			}if(cnt % 2 == 1) t *= j;
			j++;
		}if(m > 1) t *= m;
		ans += dem[t] * (dem[t] - 1) / 2;
		dem[t]++;
	}cout << ans;
	return 0;
}