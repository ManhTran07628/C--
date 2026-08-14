#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,d[MM],p[MM];
vector<pair<int,int>> adj[MM];

struct Node{ // luu dinh va duong di ngan nhat tu dinh a den b
    int u, Dist_u;
};

struct cmp{
    bool operator() (Node a,Node b) {
        return a.Dist_u > b.Dist_u;
    }
};
z
     
void dijkstra()
{
    fill(d+1,d+n+1,oo);
    priority_queue<Node, vector<Node>,cmp> q;
    q.push({1,0});
    d[1] = 0;
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u;
        if(p[u]) continue;
        p[u] = 1;
        for(auto [v,w]:adj[u]) {
            if(d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({v,d[v]});
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
        int a,b,w;
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }
    dijkstra();
    for(int i = 1;i <= n;i++) {
        cout << d[i] << ' ';
    }
    return 0;
}