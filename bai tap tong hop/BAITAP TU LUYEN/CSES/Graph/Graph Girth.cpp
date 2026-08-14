#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 2505;
vector<int> adj[MM];
vector<pair<int,int>> cycle;
int visited[MM],parent[MM],dis[MM];
int ans = LLONG_MAX;


void bfs(int x)
{
    memset(visited,0,sizeof(visited));
    memset(parent,0,sizeof(parent));
    memset(dis,0,sizeof(dis));
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(!visited[v]) {
                q.push(v);
                visited[v] = 1;
                parent[v] = u;
                dis[v] = dis[u] + 1;
            }
            else {
                if(parent[u] != v) {
                    ans = min(ans,dis[u]+dis[v]+1);
                }
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
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1;i <= n;i++) {
        bfs(i);
    }
    cout << (ans == LLONG_MAX ? -1 : ans);
    return 0;
}