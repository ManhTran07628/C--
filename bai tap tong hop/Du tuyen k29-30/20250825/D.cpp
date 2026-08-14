#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 5000+7;
const int MS = 5e6;
ll n,q,a[MM],dp[MM][MM],lim = 2e6;
ll mp[MS];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "threesum"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int k = 1;k <= n;k++) {
        vector<int> track;
        for(int i = k-1;i >= 1;i--) { // s_j = -s_i - -s_k
            int sum = -(a[i] + a[k]);
            dp[i][k] = dp[i+1][k] + dp[i][k-1] - dp[i+1][k-1] + mp[sum+lim];

            if(mp[a[i]+lim] == 0)
                track.push_back(a[i]+lim);

            mp[a[i]+lim]++;
        }
        for(auto i:track) mp[i] = 0;
    }
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << dp[l][r] << '\n';
    }
    return 0;
}