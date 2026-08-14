#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN];
int MM = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 0;i <= k+1;i++) dp[i] = i+1;
    for(int i = k+2;i <= n;i++) {
        dp[i] = (dp[i-1]+dp[i-k-1])%MM;
    }
    cout << dp[n];
    return 0;
}