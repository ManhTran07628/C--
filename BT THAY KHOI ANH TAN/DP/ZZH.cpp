#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN];
int M = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    for(int i = 4;i <= n;i++) {
        dp[i] = (4*dp[i-2]+2*dp[i-3]+dp[i-1])%M;
    }
    cout << dp[n];
    return 0;   
}