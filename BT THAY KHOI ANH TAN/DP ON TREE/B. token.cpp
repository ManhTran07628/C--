#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n;
ll dp[MM],st[MM];
vector<int> adj[MM];

void init()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v = i+1;
        cin >> u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    st[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        st[u] += st[v];
        dp[u] += dp[v];
    }
    dp[u] += st[u];
}

void solve()
{
    dfs(1,0);
    for(int i = 1;i <= n;i++) cout << dp[i] << ' ';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}