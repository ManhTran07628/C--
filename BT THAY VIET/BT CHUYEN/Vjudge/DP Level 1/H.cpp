#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int w[25];
pair<int,int> dp[1 << 21];
int n,x,sum = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans = LLONG_MAX;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> w[i];
    }
    for(int i = 0;i < (1 << n);i++) dp[i] = {LLONG_MAX,LLONG_MAX};
    dp[0].fi = 0;
    dp[0].se = 1;
    for(int mask = 1;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if((mask >> i) & 1) {
                int prev_mask = mask ^ (1 << i);
                int total = dp[prev_mask].fi;
                int steps = dp[prev_mask].se;
                if(total + w[i+1] <= x) {
                    total += w[i+1];
                }
                else {
                    total = w[i+1];
                    steps++;
                }
                pair<int,int> p{total,steps};
                dp[mask] = min(dp[mask],p);
            }
        }
    }
    int m = (1 << n) - 1;
    cout << dp[m].se;
    return 0;   
}