#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 100+7;
int n,m,a[MM][MM];

void readinput()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
}
namespace subtask2
{
    int dp[MM];
    bool check()
    {
        return (m == 1);
    }

    void solve()
    {
        if(a[1][m] == 1 || a[1][m] == 2) dp[1] = 1;
        else if(a[1][m] == 3) dp[1] = 2;
        for(int i = 2;i <= n;i++) {
            if(a[i][m] == 0) dp[i] = dp[i-1];
            if(a[i][m] == 1) {
                if(a[i-1][m] != 2) dp[i] = dp[i-1] + 1;
                else dp[i] = max(dp[i-1],dp[i-2] + 1);
            }
            else if(a[i][m] == 2) {
                if(a[i-1][m] != 1) dp[i] = dp[i-1] + 1;
                else dp[i] = max(dp[i-1],dp[i-2] + 1);
            }
            else if(a[i][m] == 3) {
                if(a[i-1][m] == 0) dp[i] = dp[i-1]+2;
                else dp[i] = max(dp[i-1]+1,dp[i-2]+2);
            }
        }
        cout << dp[n];
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    subtask2::solve();
    return 0;
}