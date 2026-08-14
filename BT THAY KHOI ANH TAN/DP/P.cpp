#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int h[2005],w[2005],dp[2005];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,L;
    cin >> n >> L;
    for(int i = 1;i <= n;i++) {
        cin >> h[i] >> w[i];
    }
    fill(dp+1,dp+n+1,1e15);
    for(int i = 1;i <= n;i++) {
        int sum = 0,dmax = 0;
        for(int j = i;j >= 1;j--) {
            dmax = max(dmax,h[j]);
            sum += w[j];
            if(sum <= L) 
                dp[i] = min(dp[i],dp[j-1]+dmax);
        }
    }
    cout << dp[n];
    return 0;
}