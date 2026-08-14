#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
ll a[201][30001],b[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "spiralp"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    ll h1 = 1,h2 = n,c1 = 1,c2 = m,j = 1;
    while(h1 <= h2 && c1 <= c2) {
        for(int i = c1;i <= c2;i++) {
            b[j] = a[h1][i];j++;
        }
        h1++;
        for(int i = h1;i <= h2;i++) {
            b[j] = a[i][c2];j++;
        }
        c2--;
        for(int i = c2;i >= c1;i--) {
            b[j] = a[h2][i];j++;
        }
        h2--;
        for(int i = h2;i >= h1;i--) {
            b[j] = a[i][c1];j++;
        }
        c1++;
    }
    ll ans1 = 1;
    n = n*m;
    fill(dp+1,dp+n+1,1e9);
    dp[1] = 0;
    for(int i = 1;i < n;i++) {
        if(dp[i] < 1e9) {
            ll cnt = 0;
            for(int j = 1;j <= k;j++) {
                if(i+j <= n && b[i+j] == 0) {
                    dp[i+j] = min(dp[i+j],dp[i]+1);
                    cnt++;
                }
            }
            ans1 = max(ans1,cnt);
        }
    }
    if(dp[n] == 1e9) cout << -1 << ' ' << ans1;
    else cout << dp[n] << ' ' << ans1;
    return 0;
}