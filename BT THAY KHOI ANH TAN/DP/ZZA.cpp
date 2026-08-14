#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int M = 1e9+7;
int dp[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;
    for(int i = 3;i <= n;i++) {
        dp[i] = 3*dp[i-1]+dp[i-2]-dp[i-3];
        dp[i] = (dp[i]%M+M)%M;
    }
    cout << dp[n];
    return 0;
}