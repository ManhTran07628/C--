#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],f[MAXN];
int M = 998244353;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    dp[1] = 1;
    dp[2] = 5;
    dp[3] = 11;
    f[1] = 0;
    f[2] = 12;
    f[3] = 36;
    for(int i = 4;i <= n;i++) {
        dp[i] = (4*dp[i-2]+2*dp[i-3]+dp[i-1])%M;
        f[i] = (dp[i-2]*12+dp[i-3]*12+f[i-1])%M;
    }
    cout << [n];
    return 0;   
}