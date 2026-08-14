#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,m,used[MM];
ll dist_ins[50][50],dist_out[50][MM],new_node[MM];
struct Edge{int u,v,w,id;};
vector<Edge> edges;
vector<pii> adj[MM], Nadj[MM];
struct DSU
{
    vector<int> par;
    DSU(int n) : par(n + 7) {
        for(int i = 1;i <= n;i++)
            par[i] = i;
    };

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    bool Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        par[b] = a;
        return 1;
    }
} g(MM);


void MST()
{
    sort(edges.begin(),edges.end(),[] (Edge a, Edge b){
        return a.w < b.w;
    });
    for(auto U: edges) {
        int u = U.u, v = U.v, w = U.w, id = U.id;
        if(!g.Unite(u,v)) continue;
        Nadj[u].push_back({v,w});
        Nadj[v].push_back({u,w});
        used[id] = 1; 
        // cout << u << ' ' << v << ' ' << w << '\n';
    } 
}

vector<int> listedge;
void process()
{
    for(int i = 0;i < 49;i++)
        for(int j = 0;j < 49;j++)
            dist_ins[i][j] = oo;

    for(int i = 0;i < 49;i++) dist_ins[i][i] = 0;
    for(auto U: edges) {
        int u = U.u, v = U.v, w = U.w, id = U.id;
        if(used[id]) continue;
        listedge.push_back(u);
        listedge.push_back(v);
    } 
    
    sort(listedge.begin(),listedge.end()); 
    listedge.erase(unique(listedge.begin(),listedge.end()),listedge.end());
    for(int i = 0;i < listedge.size();i++) {
        new_node[ listedge[i] ] = lower_bound(listedge.begin(),listedge.end(),listedge[i]) -
        listedge.begin();
    }
    
    for(auto U: edges) {
        int u = U.u, v = U.v, w = U.w, id = U.id;
        if(used[id]) continue;
        u = new_node[u], v = new_node[v];

        dist_ins[u][v] = w;
        dist_ins[v][u] = w;
    }
}

void floyd()
{
    for(auto k: listedge) {
        for(auto i: listedge) {
            for(auto j: listedge) {
                int I = new_node[i], J = new_node[j], K = new_node[k];
                if(dist_ins[I][J] > dist_ins[I][K] + dist_ins[K][J]) 
                    dist_ins[I][J] = dist_ins[I][K] + dist_ins[K][J];
            }
        }
    }
}

struct Node{ll u,dist_u;};
struct cmp
{
    bool operator() (Node a,Node b) {return a.dist_u > b.dist_u;}
};

void dijkstra(int st)
{
    int new_st = new_node[st];
    for(int i = 1;i <= n;i++) dist_out[new_st][i] = oo;
    dist_out[new_st][st] = 0;
    priority_queue<Node,vector<Node>,cmp> q;
    q.push({st,0});
    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int u = U.u;
        if(dist_out[new_st][u] < U.dist_u) continue;
        for(auto X:adj[u]) {
            int v = X.fi, w = X.se;
            if(dist_out[new_st][v] > dist_out[new_st][u] + w) {
                dist_out[new_st][v] = dist_out[new_st][u] + w;
                q.push({v,dist_out[new_st][v]});
            }
        }
    }


}

const int LOG = 17;
int up[MM][LOG + 1],h[MM];
ll dist_tree[MM];

void dfs(int u, vector<pii> adj[])
{
    for(auto X:adj[u]) {
        int v = X.fi, w = X.se;
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        dist_tree[v] = dist_tree[u] + w;
        dfs(v,Nadj);
    }
}

int LCK(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    for(int i = LOG;i >= 0;i--)
        if(h[ up[u][i] ] >= h[v])
            u = up[u][i];
    if(u == v) return u;
    for(int i = LOG;i >= 0;i--)
        if(up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v,w; cin >> u >> v >> w;
        edges.push_back({u,v,w,i-1});
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    MST();
    process();
    floyd();
    for(auto u: listedge) dijkstra(u);
    dfs(1,Nadj);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];

    int q; cin >> q;
    while(q--) {
        int u,v; cin >> u >> v;
        ll res = dist_tree[u] + dist_tree[v] - 2 * dist_tree[LCK(u,v)];
        for(auto x1: listedge) {
            for(auto x2: listedge) {
                ll x = dist_out[ new_node[x1] ][u] + 
                    dist_ins[ new_node[x1] ][ new_node[x2] ] + dist_out[ new_node[x2] ][v];
                res = min(res,x);
            }
        }
        cout << res << '\n';
    }


    return 0;
}
