#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
ll n,a[MM],res = -oo;
ll dp[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    dp[u] = max(dp[u],a[u]);
    priority_queue<ll> q;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        q.push(dp[v]);
        res = max(res,dp[u]);
        dp[u] = max(dp[u],dp[v] + a[u]);
    }
    if(!q.empty()) {
        ll v1 = q.top(); q.pop();
        ll v2 = 0;
        if(!q.empty()) {
            v2 = q.top();
            // cout << u << ' ' << v1 << ' ' << v2 << '\n';
            res = max(res,v1 + v2 + a[u]);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    // for(int i = 1;i <= n;i++) cout << i << ' ' << dp[i] << '\n';
    cout << res;
    return 0;
}