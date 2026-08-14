#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m;
ll P,C,a[MM],s[MM],dp[MM][1 << 6];

void readinput()
{
    cin >> n >> m >> P >> C;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= m;i++) cin >> s[i];
}

void solve()
{
    sort(a+1,a+n+1);
    for(int i = 0;i <= n;i++) {
        for(int mask = 1;mask < (1 << m);mask++) {
            dp[i][mask] = -oo;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int mask = 1;mask < (1 << m);mask++) {
            if(dp[i-1][mask] != -oo) dp[i][mask] = dp[i-1][mask];
            for(int j = 0;j < m;j++) {
                if((mask >> j & 1) && i >= s[j+1] ) {
                    int p_mask = mask ^ (1 << j);
                    ll diff = a[i] - a[i - s[j+1] + 1];
                    ll cash = P - diff*diff*C;
                    if(dp[i - s[j+1]][mask] != -oo) dp[i][mask] = max(dp[i][mask],dp[i - s[j+1]][mask] + cash);
                    dp[i][mask] = max(dp[i][mask],dp[i - s[j+1]][p_mask] + cash);
                }
            }
        }
    }
    cout << dp[n][(1 << m)-1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}