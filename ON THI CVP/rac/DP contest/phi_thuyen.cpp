#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
char a[51][51];
ll dp[51][51];
ll INF = 1e9;


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
    ll n,m,r;
    cin >> n >> m;
    ll cody;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if(a[i][j] == 'v') {
                cody = j;
            }
        }
    }
    cin >> r;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dp[i][j] = INF;
        }
    }
    for(int i = 1;i <= m;i++) {
        if(a[1][i] != '#') dp[1][i] = abs(i - cody);
    }
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == '#') continue;
            for(int k = -r;k <= r;k++) {
                ll x = j-k;
                if(x >= 1 && x <= m && a[i-1][x] != '#' ) {
                    dp[i][j] = min(dp[i][j],dp[i-1][x] + abs(k));
                }
            }
        }
    }
    ll ans = INF;
    for (int j = 1; j <= m; j++) {
        ans = min(ans, dp[n][j]);
    }
    if(ans == INF) cout << -1;
    else cout << ans;
    return 0;
}