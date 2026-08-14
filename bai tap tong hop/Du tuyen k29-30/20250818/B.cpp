#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define oo 1e18
int n,k,dp[50007][507],ans = 0;
vector<int> adj[50007];
// dp[u][k] so cac co khoang cach k tu dinh u den cac node
// trong cay con goc u

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v != par) {
            dfs(v,u);
            for(int i = 0;i < k;i++) ans += dp[u][i]*dp[v][k-i-1];
            for(int i = 0;i < k;i++) dp[u][i+1] += dp[v][i];
        }
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
    for(int i = 1;i <= n;i++) {
        dp[i][0] = 1;
    }
    dfs(1,0);
    cout << ans;
    return 0;
}