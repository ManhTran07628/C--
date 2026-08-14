#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,k,marked[MM];
vector<pii> adj[MM];

namespace subtask2
{
    ll dp[MM][MM] = {}, f[MM][MM] = {}, h[MM] = {};

    void dfs1(int u,int par)
    {
        for(auto N:adj[u]) {
            int v = N.fi, w = N.se;
            if(v == par || v == u) continue;
            h[v] = h[u] + w;
            dfs1(v,u);
        }
    }
    
    void dfs2(int u,int par)
    {
        for(auto N:adj[u]) {
            int v = N.fi, w = N.se;
            if(v == par || v == u) continue;
            dfs2(v,u);
            dp[u][v] = dp[v][v];
        }

        for(int i = 0;i < adj[u].size();i++) {
            for(int j = 0;j < adj[u].size();j++) {
                int v1 = adj[u][i].fi, v2 = adj[u][j].fi;
                if(v1 == v2 || v1 == u || v2 == u) continue;

                int dist = h[v1] + h[v2] - 2 * h[u];

                dp[u][v1] = min(dp[u][v1],dp[u][v2] + dist);
            }
        }
    }   

    void solve()
    {
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
                dp[i][j] = oo;

        for(int i = 1;i <= n;i++)
            if(adj[i].size() == 2) {
                dp[i][i] = 0;
                cout << i << '\n';
            }

        cout << adj[4].size() << ' ' << adj[5].size() << '\n';

        dfs1(1,0);
        dfs2(1,0);

        // cout << dp[1][1];
        for(int i = 1;i <= n;i++) cout << dp[i][i] << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i = 1;i <= n;i++) {
        adj[i].push_back({i,0});
    }
    for(int i = 1;i <= k;i++) {
        int u; cin >> u;
        marked[u] = 1;
    }
    subtask2::solve();
    return 0;
}