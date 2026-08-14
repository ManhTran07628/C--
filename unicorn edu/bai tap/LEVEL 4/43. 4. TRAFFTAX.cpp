#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 2e5+7;
const int LOG = 18;
int n,k,up[MM][LOG + 5];
vector<int> adj[MM];

struct Node{
    int u;
    vector<int> node;
} dp[MM][2];

void dfs1(int u)
{
    bool ok = 0;
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        up[v][0] = u;
        ok = 1;
        dfs1(v);
    }
    if(ok) dp[u][0].u = dp[u][1].u = oo;
    else {
        dp[u][0].u = 0;
        dp[u][1].u = 1;
        dp[u][1].node.push_back(u);
    }
}

int kth_ancs(int u,int h)
{
    for(int i = LOG;i >= 0;i--)
        if(h >> i & 1)
            u = up[u][i];
    return u;
}

void dfs(int u)
{
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        
        dfs(v);
    }

    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];

    dfs(1);
    // cout << min(dp[1][1].u,dp[1][0].u) << '\n';
    // for(auto x: dp[1][0].node) cout << x << ' ';
    // cout << '\n';
    // for(auto x: dp[1][1].node) cout << x << ' ';
    return 0;
}