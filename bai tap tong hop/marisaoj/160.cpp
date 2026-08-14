#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],b[N];
ll dp[N][2][3];

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
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    dp[1][0][1] = a[1];
    dp[1][1][1] = b[1];
    for(int i = 2;i <= n;i++) {
        dp[i][0][2] = dp[i-1][0][1] + a[i];
        dp[i][0][1] = max(dp[i-1][1][1],dp[i-1][1][2]) + a[i];
        dp[i][1][2] = dp[i-1][1][1] + b[i];
        dp[i][1][1] = max(dp[i-1][0][1],dp[i-1][0][2]) + b[i];
    }
    cout << max({dp[n][0][1],dp[n][0][2],dp[n][1][1],dp[n][1][2]});
    return 0;
}