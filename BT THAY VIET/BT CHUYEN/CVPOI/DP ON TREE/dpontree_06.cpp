#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,h[MM],distA[MM],distB[MM];
vector<int> adj[MM];
int a = 0, maxx = 0, b = 0;

void dfs1(int u,int par,int &x)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs1(v,u,x);
    }
    if(maxx < h[u]) {
        x = u;
        maxx = h[u];
    }
}

void dfs(int u,int par,int dist[])
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        dist[v] = dist[u] + 1;
        dfs(v,u,dist);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1,0,a);
    maxx = 0;
    memset(h,0,sizeof(h));
    dfs1(a,0,b);
    dfs(a,0,distA);
    dfs(b,0,distB);
    // cout << a << ' ' << b << '\n';
    for(int i = 1;i <= n;i++) cout << max(distA[i],distB[i]) << ' ';
    return 0;
}
