#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp0[MAXN],dp1[MAXN],dp2[MAXN];
int MOD = 1e9+7;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp0[1] = 1;
    dp1[1] = 1;
    dp2[1] = 1;
    for(int i = 2;i <= n;i++) {
        dp0[i] += dp0[i-1]+dp1[i-1]+dp2[i-1];
        dp1[i] += dp0[i-1]+dp2[i-1];
        dp2[i] += dp0[i-1]+dp1[i-1]+dp2[i-1];
        dp0[i] %= MOD;
        dp1[i] %= MOD;
        dp2[i] %= MOD;
    }
    cout << (dp0[n]+dp1[n]+dp2[n])%MOD;
    return 0;
}