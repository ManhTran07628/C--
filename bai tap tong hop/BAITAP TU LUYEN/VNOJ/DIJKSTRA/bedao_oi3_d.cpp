#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,m,k,p[MM],t[MM],boba[MM],ok[MM];
struct path{ll dist,source;} dist1[MM],dist2[MM];
vector<pii> adj[MM];
struct Node{ll u,dist_u,source;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};
priority_queue<Node,vector<Node>,cmp> q;

void dijkstra()
{
    for(int i = 1;i <= n;i++) {
        dist1[i] = dist2[i] = {(ll) oo, -1};
        if(boba[i]) {
            dist1[i].dist = 0;
            dist1[i].source = i;
            q.push({i,0,i});
        }
    }


    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u, root = U.source;
        if(dist2[u].dist < U.dist_u) continue;
        // cout << u << '\n';
        for(auto X:adj[u]) {    
            int v = X.fi, w = X.se;
            if(dist1[v].dist > U.dist_u + w) {
                if(dist1[v].source != root) {
                    dist2[v] = dist1[v];
                    q.push({v, dist2[v].dist, dist2[v].source});
                }
                
                dist1[v] = {U.dist_u + w, root};
                q.push({v, dist1[v].dist, dist1[v].source});
            }
            else if(dist2[v].dist > U.dist_u + w && dist1[v].source != root) {
                    dist2[v].dist = U.dist_u + w;
                    dist2[v].source = root;
                    q.push({v, dist2[v].dist, dist2[v].source});
                }
        }   
    }
}
// ta se tao ra duong di ngan nhat va duong di ngan thu hai khác nguồn

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "milktea"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    for(int i = 1;i <= k;i++) {
        cin >> p[i] >> t[i];
        if(t[i] == 0) ok[ p[i] ] = 1;
        boba[ p[i] ] = 1;
    }
    dijkstra();

    for(int i = 1;i <= n;i++) {
        if(!boba[i]) cout << dist1[i].dist << ' ';
        else {
            if(ok[i]) cout << 0 << ' ';
            else {
                if(dist1[i].source != i) cout << dist1[i].dist << ' ';
                else cout << dist2[i].dist << ' ';
            }
        }
    }
    return 0;
}
