#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e3 + 7;
int n,a[MM],b[MM];


namespace subtask1
{
    int res = oo, min_step = oo;
    void Try(int id,int sum1,int sum2,int cnt)
    {
        if(id > n) {
            int dif = abs(sum1 - sum2);
            if(res > dif) {
                res = dif;
                min_step = cnt;
            }
            else if(res == dif) min_step = min(min_step,cnt);
            return;
        }
        Try(id+1,sum1 + a[id],sum2 + b[id],cnt);
        Try(id+1,sum1 + b[id],sum2 + a[id],cnt + 1);
    }

    void solve()
    {
        Try(1,0,0,0);
        cout << res << ' ' << min_step;
    }
}

namespace sol
{
    const int lim = 6e3 + 7;
    int dp[MM][lim + 7];
    void solve()
    {
        int sum = 0;
        for(int i = 0;i <= n;i++)
            for(int j = 0;j <= lim;j++) 
                dp[i][j] = oo;

        for(int i = 1;i <= n;i++) sum += a[i] + b[i];

        dp[0][0] = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 0;j <= lim;j++) {
                if(j >= a[i]) 
                    dp[i][j] = min(dp[i][j],dp[i - 1][j - a[i]]);
                if(j >= b[i])
                    dp[i][j] = min(dp[i][j],dp[i - 1][j - b[i]] + 1);
            }

        int res = oo,cnt = oo;
        for(int j = 0;j <= lim;j++) {
            if(dp[n][j] != oo) {
                if(res > abs(j * 2 - sum)) {
                    res = abs(j * 2 - sum);
                    cnt = dp[n][j];
                }
                else if(res == abs(j * 2 - sum)) {
                    cnt = min(cnt,dp[n][j]);
                }
            }
        }
        cout << cnt;
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
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i];
    }
    sol::solve();
    return 0;
}
