#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
ll n,c;
ll a[MM],dp[MM],ans[MM];
vector<int> adj[MM];

void dfs1(int u,int par)
{
    dp[u] = a[u] - c * ((ll) adj[u].size() - 2);
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs1(v,u);
        dp[u] += max(0ll,dp[v]);
    }
}

void dfs2(int u,int par,ll maxval)
{
    ans[u] = dp[u] + max(0ll,maxval);
    for(auto v:adj[u]) {
        if(v == par) continue;
        ll newval = ans[u] - max(0ll,dp[v]);
        dfs2(v,u,newval);
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
    cin >> n >> c;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i = 1;i <= n;i++) cout << ans[i] - 2 * c << ' ';
    return 0;
}