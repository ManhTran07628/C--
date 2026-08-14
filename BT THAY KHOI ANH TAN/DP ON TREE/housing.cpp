#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,c,a[MM];
vector<int> adj[MM];
ll dp[MM][2];


void dfs(int u,int par)
{
    dp[u][1] = a[u];
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += max(dp[v][0],dp[v][1] - 2 * c);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "housing"
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
    // for(int i = 1;i <= n;i++) dp[i][0] = dp[i][1] = -oo;
    dfs(1,0);
    cout << max(dp[1][0],dp[1][1]);
    return 0;
}