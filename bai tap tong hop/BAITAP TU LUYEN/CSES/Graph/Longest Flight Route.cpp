#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
int n,m,parent[MM],degree[MM],dp[MM]; 
vector<int> adj[MM],back_edge[MM],topo;
// dp[i] duong di dai nhat di qua dinh i
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
        dp[i] = LLONG_MIN;
    }
    Kahn();
    dp[1] = 1; // track duong di dai nhat
    for(int i = 1;i <= n;i++) {
        int cur = topo[i];
        for(auto prev: back_edge[cur]) {
            if(dp[prev]+1 > dp[cur]) {
                dp[cur] = dp[prev]+1;
                parent[cur] = prev;
            }
        }
    }
    if(dp[n] >= 0) {
        cout << dp[n] << '\n';
        int cur = parent[n];
        vector<int> ans;
        ans.push_back(n);
        while(cur != 1) {
            ans.push_back(cur);
            cur = parent[cur];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        for(auto i:ans) cout << i << ' ';

    }
    else cout << "IMPOSSIBLE";

    return 0;
}