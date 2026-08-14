#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e4+7;
const int sz = 4;
int n,a[sz + 5][MM];
ll dp[MM][1 << sz],sum[MM][1 << sz];
vector<int> valid[1 << sz];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            // cout << a[i][j] << ' ';
        }
        // cout << '\n';
    }
    
    for(int mask = 0;mask < (1 << sz);mask++) {

        if(mask & (mask >> 1)) continue;
        for(int smask = 0;smask < (1 << sz);smask++) {
            if(smask & (smask >> 1)) continue;
            
            if( !(mask & (smask)) ) {
                valid[mask].push_back(smask);
                bitset<5> st1 = smask;
                // cout << st1 << '\n';
            }
        }
        // cout << '\n';
        
    }
    for(int i = 1;i <= n;i++) {
        
        // cout << i << ' ';
        for(int mask = 0;mask < (1 << sz);mask++) {
            bitset<5> st = mask;
            // cout << i << ' ' << st << ' ';
            for(int j = 0;j < sz;j++)
                if(mask >> j & 1) sum[i][mask] += a[j+1][i];

            // cout << sum[i][mask] << '\n';
        }

    }

    for(int i = 0;i <= n;i++) 
        for(int mask = 0;mask < (1 << sz);mask++)
            dp[i][mask] = -oo;
    dp[0][0] = 0;

    for(int i = 1;i <= n;i++) 
        for(int mask = 0;mask < (1 << sz);mask++) {
            dp[i][mask] = dp[i-1][mask];
            if(mask & (mask >> 1)) continue;
            for(auto smask : valid[mask]) {
                dp[i][mask] = max(dp[i][mask],dp[i-1][smask] + sum[i][mask]);
            }

        }

    ll res = -oo;
    for(int i = 1;i < (1 << sz);i++)
        res = max(res,dp[n][i]);
    cout << res;
    return 0;
}