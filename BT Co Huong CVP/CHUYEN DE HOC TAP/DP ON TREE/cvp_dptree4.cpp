#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 5e4 + 7;
int n,k;
ll dp[MM][201],f[MM][201];
// dp : so cach di tu goc -> con
// f : tong so cach 
vector<int> adj[MM];

void dfs(int u,int par)
{
    dp[u][0]++;
    // f[u][0]++;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        for(int i = 1;i <= k;i++) {
            dp[u][i] += dp[v][i-1];// + dp[v][i];
            f[u][i] += f[v][i];
        }
    }
    for(int i = 0;i < adj[u].size();i++) {
        for(int j = i + 1;j < adj[u].size();j++) {
            int a = adj[u][i], b = adj[u][j];
            if(a == par || b == par) continue;

            for(int d = 1;d < k;d++) {
                if(d - 1 >= 0 && k - d - 1 >= 0)
                    f[u][k] += dp[a][d - 1] * dp[b][k - d - 1];
            }
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
    for(int i = 1;i <= n;i++) {
        int u; cin >> u;
        if(u == 0) continue;
        adj[i].push_back(u);
        adj[u].push_back(i);
    }
    dfs(1,0);
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        res += dp[i][k];
    }
    cout << res + f[1][k];
    return 0;
}