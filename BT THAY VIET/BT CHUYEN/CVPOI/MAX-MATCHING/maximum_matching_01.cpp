#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,m,k,vis[MM],matchY[MM];
vector<int> adj[MM];


bool dfs(int u)
{
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        vis[v] = 1;

        if(!matchY[v] || dfs(matchY[v])) {
            matchY[v] = u;
            return 1;
        }

    }
    return 0;
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
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
    }
    int max_matching = 0;
    for(int i = 1;i <= n;i++) {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) max_matching++;
    }
    cout << max_matching;
    return 0;
}