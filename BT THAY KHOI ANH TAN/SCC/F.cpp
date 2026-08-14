#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 1e5+7;
int n,m,low[MM],num[MM],timeDFS = 0,scc_Node[MM],vis[MM];
int B = 0,comp[MM],cm = 0,Node[MM];
vector<pair<int,int>> bridge;
map<pair<int,int>,int> mp;
vector<int> adj[MM],Nadj[MM];
stack<int> st;

void load_graph()
{
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs_scc(int u,int par)
{
    low[u] = num[u] = ++timeDFS;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!num[v]) {
            dfs_scc(v,u);
            low[u] = min(low[u],low[v]);
            if(low[v] == num[v]) {
                bridge.push_back({u,v});
                bridge.push_back({v,u});
                mp[{u,v}] = 1;
                mp[{v,u}] = 1;
                B++;
            }
        }
        else low[u] = min(low[u],num[v]);
    }
}

int h[MM],cur_h = 0;

void dfs_a(int u,int &x)
{
    vis[u] = 1;
    if(h[u] > cur_h) {
        x = u;
        cur_h = h[u];
    }
    for(auto v:Nadj[u]) {
        if(!vis[v]) {
            h[v] = h[u] + 1;
            dfs_a(v,x);
        }
    }
}

int a = 1,b = 1;
int find_diameter()
{
    dfs_a(1,a);
    memset(vis,0,sizeof(vis));
    memset(h,0,sizeof(h));
    cur_h = 0;
    dfs_a(a,b);
    return cur_h;
}

void dfs_comp(int u,int c)
{
    comp[u] = c;
    for(auto v:adj[u]) {
        if(comp[v]) continue;
        if(mp[{u,v}]) continue;
        dfs_comp(v,c);
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) if(!num[i]) dfs_scc(i,i);
    for(int i = 1;i <= n;i++) {
         if(!comp[i]) {
            dfs_comp(i,++cm);
            Node[comp[i]] = i;
         }
    }
    for(auto e:bridge) {
        Nadj[comp[e.fi]].push_back(comp[e.se]);
        Nadj[comp[e.se]].push_back(comp[e.fi]);
    }
    int d = find_diameter();
    cout << a << ' ' << b << ' ' << B-d << '\n';
    cout << comp[a] << ' ' << comp[b] << ' ' << B-d;
}






signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "NOBRIDGE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    load_graph();
    solve();
    return 0;
}