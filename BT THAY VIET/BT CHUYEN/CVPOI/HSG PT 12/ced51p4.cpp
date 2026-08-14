#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3;
const int MOD = 998244353;
int n,m,k;
ll dp[MM + 7][2 * MM + 7][5];

ll add(ll &a, ll &b)
{
    return (a + b) % MOD;
}

// dp[i][k][1 -> 4]
// số cách tạo ra k tplt xét đến vị trí i trong đó điền vị trí i+1 là các trạng thái 1 - > 4
// 1 - XO
// 2 - OX
// 3 - OO
// 4 - XX
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> k; 

    dp[1][2][1] = dp[1][2][2] = 1; 
    dp[1][1][3] = dp[1][1][4] = 1;
    for(int i = 1;i <= m;i++) {
        for(int t = 1;t <= k;t++) {

            // th1 
            dp[i+1][t][1] = add(dp[i+1][t][1],dp[i][t][1]);
            dp[i+1][t+2][2] = add(dp[i+1][t+2][2],dp[i][t][1]);
            dp[i+1][t][3] = add(dp[i+1][t][3],dp[i][t][1]);
            dp[i+1][t][4] = add(dp[i+1][t][4],dp[i][t][1]);
            
            // th2
            dp[i+1][t+2][1] = add(dp[i+1][t+2][1],dp[i][t][2]);
            dp[i+1][t][2] = add(dp[i+1][t][2],dp[i][t][2]);
            dp[i+1][t][3] = add(dp[i+1][t][3],dp[i][t][2]);
            dp[i+1][t][4] = add(dp[i+1][t][4],dp[i][t][2]);

            // th3
            dp[i+1][t+1][1] = add(dp[i+1][t+1][1],dp[i][t][3]);
            dp[i+1][t+1][2] = add(dp[i+1][t+1][2],dp[i][t][3]);
            dp[i+1][t][3] = add(dp[i+1][t][3],dp[i][t][3]);
            dp[i+1][t+1][4] = add(dp[i+1][t+1][4],dp[i][t][3]);
            
            // th4
            dp[i+1][t+1][1] = add(dp[i+1][t+1][1],dp[i][t][4]);
            dp[i+1][t+1][2] = add(dp[i+1][t+1][2],dp[i][t][4]);
            dp[i+1][t+1][3] = add(dp[i+1][t+1][3],dp[i][t][4]);
            dp[i+1][t][4] = add(dp[i+1][t][4],dp[i][t][4]);
        }
    }
    cout << (dp[m][k][1] + dp[m][k][2] + dp[m][k][3] + dp[m][k][4]) % MOD;
    return 0;
}