#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 2e5+7;
vector<int> adj[MM];
int visited[MM],costA[MM],costN[MM];
void bfs(int x,int *cost)
{
    queue<int> q;
    visited[x] = 1;
    q.push(x);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
                cost[v] = min(cost[v],cost[u]+1);
            }
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        costA[i] = LLONG_MAX;
        costN[i] = LLONG_MAX;
    }
    costA[1] = 0;
    costN[n] = 0;
    bfs(1,costA);
    memset(visited,0,sizeof(visited));
    bfs(n,costN);
    for(int i = 1;i <= n;i++) {
        if(costA[i] != LLONG_MAX && costN[i] != LLONG_MAX) {
            cout << costA[i] + costN[i] << ' '; 
        }
        else cout << -1 << ' ';
    }
    return 0;   
}