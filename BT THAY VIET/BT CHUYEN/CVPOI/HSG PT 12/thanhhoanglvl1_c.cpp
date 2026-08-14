#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q;
int dist[1001][1001],vis[1001],qdist[1001][1001];
vector<int> adj[MM];

void bfs(int st,int dist[][1001])
{
    queue<int> q;
    q.push(st); 
    for(int i = 1;i <= n;i++) dist[st][i] = oo;
    dist[st][st] = 0;
    memset(vis,0,sizeof(vis));
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(vis[v]) continue;
            if(dist[st][v] > dist[st][u] + 1) {
                dist[st][v] = dist[st][u] + 1;
                q.push(v);
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        bfs(i,dist);
    }

    while(q--) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        int cnt = 0;
        for(int i = 1;i <= n;i++) {
            bfs(i,qdist);

            for(int j = i+1;j <= n;j++) {
                if(dist[i][j] > qdist[i][j]) cnt++;
            }
        }

        cout << cnt << '\n';
        adj[x].pop_back();
        adj[y].pop_back();

    }
    return 0;
}