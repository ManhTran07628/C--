#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,visited[MM][2];
int dist[MM][2];
vector<pair<int,int>> adj[MM];
 
struct Node{
    int u,Dist_u,avail;
};
 
struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};
 
void dijkstra()
{
    priority_queue<Node,vector<Node>,cmp> q;
    // fill(dist+1,dist+n+1,oo);
    for(int i = 1;i <= n;i++) {
        dist[i][0] = dist[i][1] = oo;
    }
    dist[1][0] = dist[1][1] = 0;
    q.push({1,0,0});
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u,cur_cost = top.Dist_u, avail = top.avail;
        if(visited[u][avail]) continue;
        visited[u][avail] = 1;
        for(auto [v,w]:adj[u]) {
            if(!avail) {
                if(dist[v][1] > cur_cost + w/2) {
                    dist[v][1] = cur_cost + w/2;
                    q.push({v,dist[v][1],1});
                }
            }
            if(dist[v][avail] > cur_cost + w) {
                dist[v][avail] = cur_cost + w;
                q.push({v,dist[v][avail],avail});
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
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    dijkstra();
    cout << min(dist[n][0],dist[n][1]);
    return 0;
}