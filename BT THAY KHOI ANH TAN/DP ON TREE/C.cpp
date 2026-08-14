#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
const int MOD = 1e9+7;
int n;
vector<int> adj[MM];
ll dp[MM][2];
// 0 - white   1 - black
void init()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        dp[u][0] = dp[u][0] * (dp[v][0] + dp[v][1]);
        dp[u][1] = dp[u][1] * dp[v][0];
        dp[u][0] %= MOD;
        dp[u][1] %= MOD;
    }
}

void solve()
{
    for(int i = 1;i <= n;i++)
        dp[i][0] = dp[i][1] = 1;

    dfs(1,0);

    cout << (dp[1][0] + dp[1][1]) % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}