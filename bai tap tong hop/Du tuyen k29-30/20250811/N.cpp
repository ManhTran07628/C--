#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1000+7;
int n,m,c,dp[MM][MM],k[MM];
vector<int> adj[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "time"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> c;
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
    }
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++)
        for(int t = 0;t <= 1000;t++)
            dp[i][t] = -oo;

    dp[1][0] = 0;
    for(int j = 1;j <= 1000;j++) {
        for(int i = 1;i <= n;i++) {
            for(auto u:adj[i]) {
                if (dp[u][j-1] != oo) {
                    dp[i][j] = max(dp[i][j],dp[u][j-1]+k[i]);
                }
            }

        }
    }
    int ans = 0;
    for(int x = 1;x <= 1000;x++) {
        ans = max(ans,dp[1][x]-c*x*x);
    }
    cout << ans;
    return 0;
}