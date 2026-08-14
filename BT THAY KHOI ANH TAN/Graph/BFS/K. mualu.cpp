#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1e5  +7;
vector<int> adj[MM];
int visited[MM],cnt = 0;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v:adj[u]) {
            if(!visited[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }
    cnt++;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,x;
    cin >> n >> m >> x;
    for(int i = 1;i <= m;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        if(c >= x) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }
    cout << cnt;
    return 0;
}