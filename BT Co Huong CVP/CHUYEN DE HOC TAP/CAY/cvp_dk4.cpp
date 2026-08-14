#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
const int LOG = 18;
int n,h[MM];
struct cmp{bool operator() (pii a,pii b){return a.se > b.se;}};
priority_queue<pii,vector<pii>,cmp> q[MM];
vector<int> adj[MM];
pii maxedge[MM][3],max_child[MM];
int up[MM][LOG+1];

void dfs(int u,int par)
{
    max_child[u] = {u,h[u]};
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        dfs(v,u);
        if(max_child[u].se < max_child[v].se) max_child[u] = max_child[v];
        q[u].push(max_child[v]);
    }
    if(q[u].empty()) q[u].push({u,h[u]});
    while(q[u].size() > 2) q[u].pop();
}


int LCA(int u,int v)
{
    if(h[u] < h[v]) return LCA(v,u);

    for(int i = LOG;i >= 0;i--) 
        if(h[up[u][i]] >= h[v]) u = up[u][i];

    if(u == v) return u; // u la LCA cua u va v
    
    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

void process()
{
    dfs(1,0);
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
        }   
    }
    for(int i = 1;i <= n;i++) {
        int cnt = 0;
        maxedge[i][1].se = maxedge[i][2].se = -1;
        while(!q[i].empty()) {
            maxedge[i][++cnt] = q[i].top();
            q[i].pop();
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    process();
    for(int i = 1;i <= n;i++) {
        int res = h[i];
        // th1
        if(maxedge[i][1].se != -1) res = max(res,maxedge[i][1].se - h[i]);
        if(maxedge[i][2].se != -1) res = max(res,maxedge[i][2].se - h[i]);
        // th2
        if(maxedge[1][1].se != -1) {
            int u = maxedge[1][1].fi, v = i;
            res = max(res,h[u] + h[v] - 2 * h[LCA(u,v)]);
        }
        if(maxedge[1][2].se != -1) {
            int u = maxedge[1][2].fi, v = i;
            res = max(res,h[u] + h[v] - 2 * h[LCA(u,v)]);
        }
        cout << res << ' ';
    }
    return 0;
}