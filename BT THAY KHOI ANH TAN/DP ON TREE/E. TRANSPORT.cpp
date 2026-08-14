#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int n,a,dp[MM];
vector<int> adj[MM];

void init()
{
    cin >> n >> a;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    vector<int> child;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        child.push_back(dp[v]);
    }

    sort(child.begin(),child.end(),greater<int>());

    for(int i = 0;i < child.size();i++) 
        dp[u] = max(dp[u],child[i] + i);
    dp[u]++;
}

void solve()
{
    dfs(a,0);

    cout << dp[a]-1;

}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}