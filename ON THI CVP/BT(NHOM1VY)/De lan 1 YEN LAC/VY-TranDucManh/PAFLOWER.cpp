#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[1001],b[1001];
int dp[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i]; 
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i] + b[j] >= 0) dp[i][j] = dp[i-1][j-1]+1;
            dp[i][j] = max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    }
    cout << dp[n][n];
    return 0;
}