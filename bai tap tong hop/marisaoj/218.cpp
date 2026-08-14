#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 21;
int n,W,a[MM];
pair<int,int> dp[1 << 20]; // .fi so thung - .se trong luong

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> W;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i < (1 << n);i++) dp[i] = {10000,0};
    dp[0] = {1,0};
    for(int mask = 1;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int prev_mask = mask ^ (1 << i);
                int boxes = dp[prev_mask].fi,weight = dp[prev_mask].se;
                if(weight + a[i] <= W) dp[mask] = {boxes,weight+a[i]};
                else dp[mask] = min(dp[mask],{boxes+1,a[i]});
            }
        }
    }
    cout << dp[(1 << n)-1].fi;
    return 0;

}