#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll dp[1001][1001];
char a[1001][1001];
ll MOD = 1e9+7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    dp[1][1] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j] == '*') dp[i][j] = 0;
            else 
                dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MOD;
            //cout << dp[i][j] << " ";
        }
        //cout << '\n';
    }
    cout << dp[n][n];
    return 0;
}