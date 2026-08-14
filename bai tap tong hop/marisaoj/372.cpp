#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,L,R,X,U,V;
int a[MM],d[MM],visited[MM];
unordered_map<int,vector<int>> adj;
struct Node{
    int u, Dist_u;
};

struct cmp{
    bool operator() (Node a,Node b)
    {
        return a.Dist_u > b.Dist_u;
    }
};

void dijkstra()
{
    fill(d+1,d+n+1,oo);
    d[U] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({U,0});
    while(!q.empty()) {
        Node top = q.top(); q.pop();
        int u = top.u, Cur_dist = top.Dist_u;
        if(visited[u]) continue;
        visited[u] = 1;
        // Type 1 : Move to i-1 cost L
        if(u > 1 && d[u-1] > d[u] + L) {
            d[u-1] = d[u] + L;
            q.push({u-1,d[u-1]});
        }
        // Type 2 : Move to i+1 cost R
        if(u < n && d[u+1] > d[u] + R) {
            d[u+1] = d[u] + R;
            q.push({u+1,d[u+1]});
        }
        // Type 3 : Move to j (if A_i = A_j) cost X
        for(auto v : adj[a[u]]) {
            if(d[v] > d[u] + X) {
                d[v] = d[u] + X;
                q.push({v,d[v]});
            }
        }
        adj[a[u]].clear();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> L >> R >> X >> U >> V;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        adj[a[i]].push_back(i);
    }
    dijkstra();
    int ans = 0;
    cout << d[V];
    return 0;
}