#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,k,a[MM],c[MM];

namespace subtask12
{
    ll dp[MM][2];
    void solve()
    {
        memset(dp,-1,sizeof(dp));

        for(int i = 1;i < k;i++) dp[i][0] = dp[i][1] = 0;

        for(int i = k;i <= n;i++) {
            dp[i][
            for(int j = 1;j < i;j++) {

            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> c[i];

    return 0;
}