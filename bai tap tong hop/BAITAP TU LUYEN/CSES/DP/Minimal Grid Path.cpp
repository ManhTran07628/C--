#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 3e3+7;
int n,dp[MM][MM];
char A[MM][MM];
string f[MM][MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++) {
            cin >> A[i][j];
        }

    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= n;j++)
            dp[i][j] = oo;
    
    
    dp[1][1] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(dp[i][j] > dp[i-1][j] + A[i][j]) {
                dp[i][j] = dp[i-1][j] + A[i][j];
                f[i][j] = f[i-1][j] + A[i][j];
            }
            if(dp[i][j] > dp[i][j-1] + A[i][j]) {
                dp[i][j] = dp[i][j-1] + A[i][j];
                f[i][j] = f[i][j-1] + A[i][j];
            }
        }
    }
    cout << f[n][n];
    return 0;
}