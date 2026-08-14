#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 5e4 + 7;
int n,k;
vector<int> adj[MM];
ll dp[MM][501], res = 0;


void dfs(int u,int par)
{
    dp[u][0] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        
        for(int i = 0;i < k;i++) 
            res += dp[u][i] * dp[v][k - i - 1];

        for(int i = 1;i <= k;i++) {
            dp[u][i] += dp[v][i - 1];
        }

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
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    cout << res;
    return 0;
}