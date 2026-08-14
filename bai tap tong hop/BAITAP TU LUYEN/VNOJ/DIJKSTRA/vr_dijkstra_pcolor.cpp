#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e5+7;
int n,c[MM],st,en;
ll L,R,C,dist[MM];
vector<int> adj[MM];
struct Node{int u;ll dist_u;};
struct cmp
{
    bool operator() (Node a, Node b) {return a.dist_u > b.dist_u;}
};

void dijkstra()
{
    fill(dist+1,dist+n+1,oo);
    dist[st] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;
        
        if(u + 1 <= n && dist[u+1] > dist[u] + R) {
            dist[u+1] = dist[u] + R;
            q.push({u+1,dist[u+1]});
        }

        if(u - 1 >= 1 && dist[u-1] > dist[u] + L) {
            dist[u-1] = dist[u] + L;
            q.push({u-1,dist[u-1]});
        }

        for(auto v:adj[ c[u] ]) {
            if(dist[v] > dist[u] + C) {
                dist[v] = dist[u] + C;
                q.push({v,dist[v]});
            }
        }

    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> R >> C;
    cin >> st >> en;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        adj[ c[i] ].push_back(i);
    }
    dijkstra();
    cout << dist[en];
    return 0;
}