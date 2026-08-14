#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll dp[MAXN],d[MAXN];
ll MOD = 14062008;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= k;i++) {
        int a;
        cin >> a;
        d[a] = 1;
    }
    dp[1] = 1;
    for(int i = 2;i <= n;i++) {
        dp[i] = (dp[i-1]%MOD+dp[i-2]%MOD)%MOD;
        if(d[i] == 1) dp[i] = 0;
    }
    cout << dp[n];
    return 0;
}