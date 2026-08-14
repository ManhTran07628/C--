#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 16;
int n,a[MM + 5][MM + 5],dp[1 << MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> a[i][j];
        }
    }
    // for(int i = 0;i < n;i++)
    //     dp[1 << i][i] = a[i][i]
    for(int mask = 1;mask < (1 << n);mask++) 
        for(int i = 0;i < n;i++)
            dp[mask][i] = oo;

    // cout << dp[0][0] << ' ';
    for(int mask = 1;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {

            if(mask >> i & 1) {

                int pmask = mask ^ (1 << i);
                for(int j = 0;j < n;j++) {

                    if(mask >> j & 1) dp[mask][i] = min(dp[mask][i],dp[pmask][j] + a[j][i]);
    

                }

            }

        }
    }
    int res = oo;
    for(int i = 0;i < n;i++) res = min(res,dp[ (1 << n) - 1 ][i]);
    cout << res;
    return 0;
}