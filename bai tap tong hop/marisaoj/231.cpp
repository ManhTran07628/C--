#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,k;
ll dp[MM][101],res = 0;
vector<int> adj[MM];
map<ll,int> mp;

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);

        for(int i = 0;i < k;i++) {
            res += (dp[u][i] * dp[v][k - i - 1]);
        }

        for(int i = 1;i <= k;i++) {
            dp[u][i] += dp[v][i-1];
        }


    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } 
    for(int i = 1;i <= n;i++) dp[i][0] = 1;
    dfs(1,0);
    cout << res;
    return 0;
}