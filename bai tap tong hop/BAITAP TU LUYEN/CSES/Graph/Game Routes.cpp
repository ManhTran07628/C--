#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,m,parent[MM],degree[MM],dp[MM]; 
vector<int> adj[MM],back_edge[MM],topo;
// dp[i] duong di dai nhat di qua dinh i
int MOD = 1e9+7;
void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= n;i++) {
        if(degree[i] == 0) 
            q.push(i);
    }
    topo.push_back(0);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(auto v:adj[u]) {
            degree[v]--;
            if(degree[v] == 0) {
                q.push(v);
                parent[v] = u;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        degree[v]++;
        adj[u].push_back(v);
        back_edge[v].push_back(u);
    }
    Kahn();
    dp[1] = 1;
    for(int i = 1;i <= n;i++) {
        int cur = topo[i];
        for(auto prev: back_edge[cur]) {
            dp[cur] = (dp[cur]+dp[prev])%MOD;
        }
    }
    cout << dp[n];
    return 0;
}