#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
int n,m,vis[MM],flag = 1,par[MM],h[MM];
vector<int> adj[MM],steps;
vector<pair<int,int>> cyclelist;
map<pair<int,int>,int> kt;
vector<int> path;
void dfs(int u)
{
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(!vis[v]) {
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
        else {
            if(v != par[u] && h[u]-h[v]+1 >= 4) {
                cyclelist.push_back({v,u});
            } 
        }
    }
}

bool valid_check(int st,int endd)
{
    int cur = endd;
    while(cur != st) {
        path.push_back(cur);
        cur = par[cur];
    }
    path.push_back(st);
    reverse(path.begin(),path.end());
    for(int i = 0;i < path.size();i++) {
        for(int j = i+2;j < path.size();j++) {
            if(i == 0 && j == path.size()-1) continue;
            if(i == path.size()-1 && j == 0) continue;
            if(i == j+1 || i == j) continue;
            int u = path[i], v = path[j];
            if(kt[{u,v}]) return 0;
        }
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        kt[{u,v}] = 1;
        kt[{v,u}] = 1;
    }
    dfs(1);
    memset(vis,0,sizeof(0));
    for(auto p:cyclelist) {
        if(valid_check(p.fi,p.se)) {
            for(auto i:path) cout << i << ' ';
            return 0;
        }
        path.clear();
    }
    cout << "no";
    return 0;
}