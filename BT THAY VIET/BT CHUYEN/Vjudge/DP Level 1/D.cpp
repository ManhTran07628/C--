#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],c[MAXN];
const int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int s = c[i];s <= x;s++) {
            dp[s] = (dp[s]+dp[s-c[i]])%MOD;
        }
    }
    cout << dp[x];
    return 0;
}