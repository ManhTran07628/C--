#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 21;
const int MOD = 1e9 + 7;
int n,a[MM + 5][MM + 5];
ll dp[21][(1 << 20) + 500]; // ghep nam thu i voi nu thu j

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];

    dp[0][0] = 1;

    for(int mask = 1;mask < (1 << n);mask++) { // duyet cac ban nam trong tap mask
        int i = __builtin_popcount(mask); // xet ban nam thu i
        for(int j = 0;j < n;j++) { // xet ban nu thu j
            int pmask = mask ^ (1 << j);
            if( (mask >> j & 1) && a[i][j+1] == 1 )
                dp[i][mask] = (dp[i][mask] + dp[i-1][pmask]) % MOD;
        }
    }
    cout << dp[n][(1 << n) - 1];
    
    return 0;
}
