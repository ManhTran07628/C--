#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],dp1[N][4],dp2[N][4];
ll n;
const int inf = 1e18;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i <= n;i++) {
        for (int j = 1;j <= 3;j++) {
            dp1[i][j] = dp2[i][j] = inf;
        }
    }
    for (int j = 1;j <= 3;j++) {
        dp1[0][j] = dp2[0][j] = 0; 
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 3;j++) {
            for(int k = 1;k <= j;k++) {
                dp1[i][j] = min(dp1[i][j],dp1[i-1][k] + (a[i] != j));
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= 3;j++) {
            for(int k = j;k <= 3;k++) {
                dp2[i][j] = min(dp2[i][j],dp2[i-1][k] + (a[i] != j));
            }
        }
    }
    ll ans = inf;
    for(int i = 1;i <= 3;i++) {
        ans = min({ans,dp1[n][i],dp2[n][i]});
    }
    cout << ans;
    return 0;
}