#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m;
vector<int> adj[MM];
int low[MM],num[MM],deleted[MM],timeDFS = 0,cnt = 0,isleaf[MM];

void dfs(int u,int par)
{
    num[u] = low[u] = ++timeDFS;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!num[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(num[v] == low[v] && isleaf[v]) {
                cnt++;
            }
        }
        else low[u] = min(low[u],num[v]);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "NOBRIDGE"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        vector<int> &v = adj[i];
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        if(adj[i].size() == 1) isleaf[i] = 1;
    }   
    // for(int i = 1;i <= n;i++) if(isleaf[i]) cout << i << '\n';
    dfs(1,0);
    cout << cnt;
    return 0;
}