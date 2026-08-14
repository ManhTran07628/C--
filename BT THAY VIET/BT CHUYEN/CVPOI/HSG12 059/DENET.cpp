#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e4 + 7;
int n,sz[MM];
vector<int> adj[MM],List;

void dfs(int u,int par)
{
    sz[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

void dfs2(int u,int par)
{
    bool valid = 1;
    for(auto v:adj[u]) {
        if(v == par) {
            if(n - sz[u] > n / 2) valid = 0;
        }
        else {
            if(sz[v] > n / 2) valid = 0;
        }
    }
    if(valid) List.push_back(u);
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs2(v,u);
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
    dfs(1,0);
    dfs2(1,0);
    if(List.empty()) cout << "NONE";
    else {
        sort(List.begin(),List.end());
        for(auto e:List) cout << e << '\n';
    }
    return 0;
}
