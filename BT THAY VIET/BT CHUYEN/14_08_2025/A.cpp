#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5000+7,MN = 5e6;
int n,q,a[MM],lt[MN+7],lim = 2e6;
ll dp[MM][MM];
vector<int> touched;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int r = 1;r <= n;r++) {
        for(auto pos:touched) lt[pos] = 0;
        touched.clear();
        for(int i = r-1;i >= 1;i--) {
            int s = - a[i] - a[r];
            dp[i][r] += lt[a[i]+lim];  
            if(!lt[s+lim]) touched.push_back(s+lim);
            lt[s+lim]++;
        }
    }

    for(int len = 2;len <= n;len++) {
        for(int i = 1;i+len <= n;i++) {
            int l = i,r = len+i;
            dp[l][r] += dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1];
        }
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
    return 0;   
}