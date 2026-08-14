#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 100 + 7;
int n,h[MM],vis[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        dfs(v,u);   
    }
}


bool ok1 = 1;
// turns = 0 -> AN   turns = 1 -> BINH
void solve(int u,int par,int turns)
{
    // cout << u << ' ' << turns << '\n';
    if(vis[u]) return;
    vis[u] = 1;
    if(turns == 1) {
        int v = -1, depth = 0;
        for(auto x:adj[u]) {
            if(vis[x] || x == u) continue;
            if((h[x] + 1) % 2 == 0 && h[x] > depth) {
                depth = h[x];
                v = x;
            }
        }
        if(v != -1) solve(v,u,turns ^ 1);
        else {
            for(auto x:adj[u]) {
                if(vis[x] || x == u) continue;
                v = x;
            }
            if(v == -1) ok1 = 0;
            else solve(v,u,turns ^ 1);
        }
    }
    else {
        int v = -1, depth = 0;
        for(auto x:adj[u]) {
            if(vis[x] || x == u) continue;
            if((h[x] + 1) % 2 == 1 && h[x] > depth) {
                depth = h[x];
                v = x;
            }
        }
        if(v != -1) solve(v,u,turns ^ 1);
        else {
            for(auto x:adj[u]) {
                if(vis[x] || x == u) continue;
                v = x;
            }
            if(v == -1) return;
            else solve(v,u,turns ^ 1);
        }
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

    // dfs(5,-1);
    // for(int i = 1;i <= n;i++) cout << i << ' ' << h[i] << '\n';
    // vector<int> vec;
    for(int i = 1;i <= n;i++) {
        fill(h+1,h+n+1,0);
        fill(vis+1,vis+n+1,0);
        dfs(i,-1);
        solve(i,-1,1);
        
        if(!ok1) cout << i << ' ';
        ok1 = 1;

    }

    
    return 0;
}