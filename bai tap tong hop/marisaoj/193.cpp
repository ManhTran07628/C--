#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
const int LOG = 16;
ll n,q,dmax[MM][LOG+1],up[MM][LOG+1],high[MM],lg2[MM];
vector<pair<int,int>> adj[MM];

void BuildLog2Arr()
{
    for(int i = 2;i < MM;i++) {
        lg2[i] = lg2[i/2] + 1;
    }
}

void dfs(int u)
{
    for(auto [v,w]:adj[u]) {
        if(v != up[u][0]) {
            dmax[v][0] = w;
            up[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}

void process()
{
    BuildLog2Arr();
    dfs(1);
    // dmax[i][j] : trong so max tinh den to tien 2^j cua dinh i
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[up[i][j-1]][j-1];
            dmax[i][j] = max(dmax[i][j-1],dmax[up[i][j-1]][j-1]);
        }
    }
}

ll Lca(ll u,ll v)
{
    if(high[v] > high[u]) swap(u,v);

    for(int i = LOG;i >= 0;i--) {
        if(high[up[u][i]] >= high[v]) 
            u = up[u][i];
    }
    if(u == v) return u;

    for(int i = LOG;i >= 0;i--) {
        if(up[u][i] != up[v][i]) {
            u = up[u][i], v = up[v][i];
        }
    }
    return up[u][0];
}

int Query(ll u,ll v)
{
    ll lca = Lca(u,v);
    ll dis_u = high[u] - high[lca];
    ll dis_v = high[v] - high[lca];

    // cout << dis_u << ' ' << dis_v << '\n';
 
    ll max_dis = 0;
    for(int i = LOG;i >= 0;i--) {
        if(dis_u >> i & 1) {
            max_dis = max(max_dis,dmax[u][i]);
            u = up[u][i];
        }
    }

    for(int i = LOG;i >= 0;i--) {
        if(dis_v >> i & 1) {
            max_dis = max(max_dis,dmax[v][i]);
            v = up[v][i];
        }
    }
    // max_dis = max({max_dis,dmax[u][0],dmax[v][0]});
    // cout << max_dis << '\n';
    return max_dis;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n >> q;
    for(int i = 1;i < n;i++) {
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    process();
    while(q--) {
        ll u,v;
        cin >> u >> v;
        cout << Query(u,v) << '\n';
    }
    return 0;
}