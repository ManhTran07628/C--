#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e3 + 7;
const int MOD = 1e9 + 7;
int n,x,a[MM];
ll dp[107][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 1;i <= n;i++) cin >> a[i];

    // dp[0] = 1;
    // for(int i = 1;i <= n;i++)
    //     for(int j = 0;j < MM;j++)   
    //         dp[i][j] = -oo;

    sort(a+1,a+n+1);
    dp[0][0] = 1;
    for(int i = 1;i <= n;i++) {

        int minn = a[i], maxx = a[i];
        for(int j = i;j >= 1;j--) {

            minn = min(minn,a[j]);
            maxx = max(maxx,a[j]);

            for(int dif = 0;dif <= x;dif++) {
                if(dp[j - 1][dif] != -oo && dif + (maxx - minn) <= x) {
                    int newdif = dif + (maxx - minn);
                    dp[i][newdif] = (dp[i][newdif] + dp[j-1][dif]) % MOD;
                }
            }

        }

    }
    ll res = 0;
    for(int i = 0;i <= x;i++)
        // if(dp[n][i] != -oo)
            res = (res + dp[n][i]) % MOD;
    cout << res;
    return 0;
}