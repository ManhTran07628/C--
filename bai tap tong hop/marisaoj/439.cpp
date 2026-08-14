#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3005;
int p[MM],cost[MM],visited[MM];
vector<int> adj[MM];
pair<int,int> edge[MM];

void bfs(int x1,int x2)
{
    memset(visited,0,sizeof(visited));
    queue<int> q;
    q.push(x1); q.push(x2);
    visited[x1] = visited[x2] = 1;
    cost[x1] = cost[x2] = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(!visited[v]) {
                cost[v] = cost[u] + 1;
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) {
        cin >> p[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> edge[i].fi >> edge[i].se;
        adj[edge[i].fi].push_back(edge[i].se);
        adj[edge[i].se].push_back(edge[i].fi);
    }
    int ans = oo;
    for(int id = 1;id <= m;id++) {
        bfs(edge[id].fi,edge[id].se);
        int total = 0;
        for(int k = 1;k <= 1000;k++) {
            total += cost[p[k]];
        }
        ans = min(ans,total);
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;   
}