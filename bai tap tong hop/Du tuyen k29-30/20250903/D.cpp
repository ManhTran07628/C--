#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,m;
pair<int,int> edges[MM];
vector<pair<int,int>> adj[MM];
map<pair<int,int>,int> chk,qr,ds;
map<int,pair<int,int>> query;
void Readinput()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
        qr[{u,v}] = qr[{v,u}] = i;
    }
}


int low[MM],num[MM],timeDFS = 0,cNode[MM],scc_sz[MM],E = 0;
int vis[MM],used[MM];
void dfs_bridge(int u,int par)
{
    low[u] = num[u] = ++timeDFS;
    for(auto x:adj[u]) {
        int v = x.fi;
        if(v == par) continue;
        if(!num[v]) {
            dfs_bridge(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] == num[v]) {
                chk[{u,v}] = chk[{v,u}] = 1;
                ds[{u,v}] = qr[{u,v}];
            }
        }
        else low[u] = min(low[u],num[v]);
    }
}

void dfs_node(int u,int par)
{
    E++;
    cNode[u] = timeDFS;
    for(auto x:adj[u]) {
        int v = x.fi;
        if(chk[{u,v}]) continue;
        if(!cNode[v]) {
            dfs_node(v,u);
        }
    }   
}

void dfs_orient(int u)
{
    vis[u] = 1;
    for(auto x:adj[u]) {
        int v = x.fi, id = x.se;
        if(used[id]) continue;
        if(chk[{u,v}]) continue;
        edges[id] = {u,v};
        used[id] = 1;
        if(!vis[v]) dfs_orient(v);
    }
}

void dfs_tree(int u,int par){
    for(auto &x: tree[u]){
        int v = x.first, id = x.second;
        if(v == par) continue;
        edges[id] = {v == comp[edges[id].first] ? edges[id].first : edges[id].second,
                     v == comp[edges[id].first] ? edges[id].second : edges[id].first};
        dfs_tree(v,u);
    }
}

void solve()
{
    dfs_bridge(1,0);
    timeDFS = 0;
    for(int i = 1;i <= n;i++) {
        if(!cNode[i]) {
            ++timeDFS;
            dfs_node(i,i);
            scc_sz[timeDFS] = E;
            E = 0;
        }
    }
    int root = 0,tmp = 0;
    for(int i = 1;i <= timeDFS;i++) {
        if(scc_sz[i] > tmp) {
            tmp = scc_sz[i];
            root = i;
        }
    }
    memset(vis,0,sizeof(vis));
    int root_v = 0;
    for(int i = 1;i <= n;i++) {
        if(cNode[i] == root) {
            root_v = i;
        }
    }
    dfs_orient(root_v);
    for(auto v:ds) {
        edges[v.se] = {v.fi.se,v.fi.fi};
    }
    cout << tmp << '\n';
    for(int i = 1;i <= m;i++) 
        cout << edges[i].fi << ' ' << edges[i].se << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Readinput();
    solve();
    return 0;
}