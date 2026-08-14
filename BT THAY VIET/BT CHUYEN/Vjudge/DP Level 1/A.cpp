#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN];
int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 6;j++) {
            if(i >= j) 
                dp[i] = (dp[i-j]+dp[i])%MOD;
        }
    }
    cout << dp[n];
    return 0;
}