#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 500+7;
ll dp[MM][MM],a,b;


void solve()
{
    cin >> a >> b;

    for(int i = 1;i <= a;i++) 
        for(int j = 1;j <= b;j++)   
            dp[i][j] = oo;
    
    for(int i = 1;i <= a;i++) {
        for(int j = 1;j <= b;j++) {


            if(i == j) dp[i][j] = 0;

            for(int x = 1;x <= i;x++) 
                dp[i][j] = min(dp[i][j],dp[x][j] + dp[i-x][j] + 1);

            for(int x = 1;x <= j;x++)
                dp[i][j] = min(dp[i][j],dp[i][x] + dp[i][j-x] + 1);

        }
    }

    cout << dp[a][b];

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}