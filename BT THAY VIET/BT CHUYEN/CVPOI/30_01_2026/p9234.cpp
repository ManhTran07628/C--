#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 20 + 7;
int n;
double a[MM][MM];
double dp[MM][1 << 20];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    for(int i = 1;i <= n;i++)   
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];

    for(int mask = 1;mask < (1 << n);mask++) {
        int i = __builtin_popcount(mask);

        for(int j = 0;j < n;j++) {
            if(mask >> j & 1) {

                if(i == 1) dp[i][mask] = a[i][j+1];

                int pmask = mask ^ (1 << j);
                dp[i][mask] = max(dp[i][mask],dp[i-1][pmask] * a[i][j+1] / 100.0);
            }
        }
    }

    cout << fixed << setprecision(6) << dp[n][(1 << n) - 1];
    return 0;
}