#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
const int MM = 1e6+7;
const int MOD = 1e9+7;
ll n,k,dp[MM][4],lt[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
            dp[u][1] *= (dp[v][2] + dp[v][3]);
            dp[u][2] *= (dp[v][1] + dp[v][3]);
            dp[u][3] *= (dp[v][1] + dp[v][2]);
            for(int i = 1;i <= 3;i++)
                dp[u][i] %= MOD;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "barnpainting"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) dp[i][1] = dp[i][2] = dp[i][3] = 1;

    for(int i = 1;i <= k;i++) {
        int b,c;
        cin >> b >> c;
        dp[b][1] = dp[b][2] = dp[b][3] = 0;
        dp[b][c] = 1;
    }
    dfs(1,0);
    cout << (dp[1][1] + dp[1][2] + dp[1][3]) % MOD;
    return 0;
}