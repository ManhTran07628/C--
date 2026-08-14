#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,st_rev[MM];
vector<pii> adj[MM];
vector<int> List;
int res = oo, cur = 0;

void dfs(int u,int par)
{
    for(auto N:adj[u]) {
        int v = N.fi, type = N.se;
        if(v == par) continue;
        dfs(v,u);
        if(type == 2) st_rev[1]++;
    }
}

void dfs2(int u,int par)
{
    bool ok = 1;
    for(auto N:adj[u]) {
        int v = N.fi;
        if(v == par) continue;
        st_rev[v] = st_rev[u];
        if(N.se == 2) st_rev[v]--;
        else st_rev[v]++;
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
        adj[u].push_back({v,1});
        adj[v].push_back({u,2});
    }
    dfs(1,0);
    dfs2(1,0);
    int res = oo;
    for(int i = 1;i <= n;i++) {
        res = min(res,st_rev[i]);
    }
    for(int i = 1;i <= n;i++) {
        if(res == st_rev[i]) {
            List.push_back(i);
        }
    }
    cout << res << '\n';
    for(auto e:List) cout << e << ' ';
    return 0;
}