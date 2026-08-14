#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 30 + 7;
int n,m,a[MM][MM];
ll dp[MM][MM][MM][MM];

int getsum(int x,int y,int u,int v)
{
    return a[u][v] - a[x - 1][v] - a[u][y - 1] + a[x - 1][y - 1];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;

        for(int j = 1;j <= m;j++) {
            a[i][j] = s[j - 1] - '0';
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            for(int u = 1;u <= n;u++)
                for(int v = 1;v <= m;v++)
                    dp[i][j][u][v] = oo;
    
    for(int row = 1;row <= n;row++) 
        for(int col = 1;col <= m;col++)
            for(int i = 1;i + row - 1 <= n;i++)
                for(int j = 1;j + col - 1 <= m;j++) {
                    int u = i + row - 1, v = j + col - 1;

                    // cout << i << ' ' << j << ' ' << u << ' ' << v << '\n';

                    if(getsum(i,j,u,v) == 0 || getsum(i,j,u,v) == row * col) 
                        dp[i][j][u][v] = 0;

                    for(int k = 1;k < u - i + 1;k++)
                        dp[i][j][u][v] = min(dp[i][j][u][v],dp[i][j][i+k-1][v] + dp[i+k][j][u][v] + 1);

                    for(int k = 1;k < v - j + 1;k++)
                        dp[i][j][u][v] = min(dp[i][j][u][v],dp[i][j][u][j+k-1] + dp[i][j+k][u][v] + 1);

                }
    cout << dp[1][1][n][m] + 1;
    
    return 0;
}