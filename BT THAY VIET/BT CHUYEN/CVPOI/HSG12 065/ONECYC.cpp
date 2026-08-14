#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,m,low[MM],num[MM],timeDFS = 0,vis[MM],bridge[MM];
vector<pii> adj[MM];
map<int,int> mp[MM];



void dfs1(int u,int par)
{
    num[u] = low[u] = ++timeDFS;
    for(auto N:adj[u]) {
        int v = N.fi, id = N.se;
        if(v == par) continue;
        if(!num[v]) {
            dfs1(v,u);
            low[u] = min(low[u],low[v]);
            if(num[u] < low[v]) bridge[id] = 1;
        }
        else low[u] = min(low[u],num[v]);
    }
}
ll k = 0;
void dfs(int u,int par)
{
    vis[u] = 1;
    k++;
    for(auto N:adj[u]) {
        int v = N.fi, id = N.se;
        if(v == par) continue;
        if(!vis[v] && bridge[id]) dfs(v,u);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "onecyc"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back({v,i});
        adj[v].push_back({u,i});
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) dfs1(i,0);
    }
    memset(vis,0,sizeof(vis));
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            k = 0;
            dfs(i,0);
            res += k * (k - 1) / 2 - (k - 1);
        }
    }
    cout << res;
    return 0;
}