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
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = (dp[i-1]*2)%MM;
        if(i-k >= 0) dp[i] = (dp[i-1]*2-dp[max(i-k-1,0LL)]+MM*MM)%MM;
    }
    cout << dp[n];
    return 0;
}