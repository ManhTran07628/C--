#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e6+7;
int n,a[MM],dist[MM];

struct Node{int u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;};
};

int dijkstra(int st)
{
    int res = oo;
    fill(dist+1,dist+n+1,oo);
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    dist[st] = 0;
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist[u] < U.dist_u) continue;

        if( (a[st] + a[u]) % 2 == 1 ) {
            res = min(res,U.dist_u);
            continue;
        }

        if(u + a[u] <= n && dist[u + a[u]] > dist[u] + 1) {
            dist[u + a[u]] = dist[u] + 1;
            q.push({u + a[u],dist[u + a[u]]});
        }

        if(u - a[u] >= 1 && dist[u - a[u]] > dist[u] + 1) {
            dist[u - a[u]] = dist[u] + 1;
            q.push({u - a[u],dist[u - a[u]]});
        }

    }

    return (res != oo ? res : -1);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for(int step = 1;step <= n;step++) {

        for(int i = 1;i <= n;i++) {
            // cout << dijkstra(i) << ' ';
        }
        
    }

    return 0;
}