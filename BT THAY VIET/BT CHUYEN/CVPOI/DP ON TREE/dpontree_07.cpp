#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,st[MM];
ll dp[MM],ans[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    st[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        st[u] += st[v];
        dp[u] += dp[v];
    }
    dp[u] += st[u] - 1;
}

void dfs2(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        ans[v] = ans[u] + n - 2 * st[v];
        dfs2(v,u);
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
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    ans[1] = dp[1];
    dfs2(1,0);
    for(int i = 1;i <= n;i++) cout << ans[i] << ' ';

    return 0;
}