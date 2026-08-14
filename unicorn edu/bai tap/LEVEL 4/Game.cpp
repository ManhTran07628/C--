#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 700+7;
int n,a[MM];
ll dp[MM][MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "game"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= n;i++) dp[i][i] = a[i];

    for(int len = 2;len <= n;len++) {
        for(int L = 1;L + len - 1 <= n;L++) {
            int R = L + len - 1;

            // dp[L][R] = dp[L+1][R];
            
            for(int k = L + 1; k <= R - 1; k++) {
                ll mid = (a[L] + a[R]) * a[k];
                dp[L][R] = max(dp[L][R],dp[L][k] + dp[k][R] + mid);
            }

        }
    }
    cout << dp[1][n];
    return 0;
}