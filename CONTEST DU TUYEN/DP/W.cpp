#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5;
int n,m,dp[MM + 5],indeg[MM];
vector<int> adj[MM + 5];

vector<int> topo;

void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= n;i++)
        if(indeg[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto v:adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) q.push(v);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        indeg[v]++;
    }
    Kahn();
    int res = 0;
    for(auto u:topo) {
        for(int v: adj[u]) {
            dp[v] = max(dp[v],dp[u] + 1);
        }
        res = max(res,dp[u]);
    }
    // cout << dp[n];
    cout << res;
    return 0;
}

