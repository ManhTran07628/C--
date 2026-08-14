#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],a[MAXN];
int MOD = 1e9+7;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for(int j = 1;j <= s;j++) {
        for(int i = 1;i <= n;i++) {
            if(j >= a[i])
               dp[j] = (dp[j]+dp[j-a[i]])%MOD;
        }
    }
    cout << dp[s];
    return 0;
}