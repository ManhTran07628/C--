#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e6+7;
vector<pair<int,int>> adj[MM];
int visited[MM],n,m;
bool bfs(int x,int year)
{
    memset(visited,0,sizeof(visited));
    int cnt = 0;
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto [v,w]:adj[u]) {
            if(!visited[v] && w > year) {
                visited[v] = 1;
                cnt++;
                q.push(v);
            }
        }
    }
    return (n-cnt) >= 2;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    if(bfs(1,0)) {
        cout << -1;
        return 0;
    }
    for(int i = 1;i <= 1000;i++) {
        if(bfs(1,i)) {
            cout << i;
            return 0;
        }
    }

    return 0;
}