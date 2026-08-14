#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2207 + 7;
const int MOD = 998244353;
int row,col,a[MM][MM];
ll dp[MM][MM],f[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "sumpath"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> row >> col;
    for(int i = 1;i <= row;i++) {
        for(int j = 1;j <= col;j++) {
            char c; cin >> c;
            a[i][j] = c - '0';
        }
    }

    dp[0][0] = 1;
    for(int i = 1;i <= row;i++)
        for(int j = 1;j <= col;j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1] + dp[i-1][j-1]) % MOD;
        }

    for(int i = 1;i <= row;i++)
        for(int j = 1;j <= col;j++) {
            f[i][j] = (f[i-1][j] + f[i][j-1] + f[i-1][j-1] + 
                dp[i][j] % MOD * a[i][j] % MOD) % MOD;
        }
    cout << f[row][col];
    return 0;
}