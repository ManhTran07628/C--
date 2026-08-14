#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n,m,low[MM],num[MM],vis[MM],timeDFS = 0;
int point[MM];
vector<int> adj[MM];


void dfs(int u,int par)
{
    num[u] = low[u] = ++timeDFS;
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(v == par) continue;
        if(!vis[v]) {
            dfs(v,u);
            low[u] = min(low[u],low[v]);
            if(u == par) {
                if(adj[u].size() > 1) point[u] = 1;
            }
            else {
                if(low[v] >= num[u]) point[u] = 1;
            }
        }   
        else {
            low[u] = min(low[u],num[v]);
        }
    };
}

// 5 5
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int comps = 0;
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            dfs(i,i);
            comps++;
        }
    }
    for(int i = 1;i <= n;i++) {
        // cout << i << ' ' << num[i] << ' ' << low[i] << '\n';
        // cout << i << ' ' << point[i] << '\n';
        if(!point[i]) cout << comps << '\n';
        else {
            set<int> st;
            for(auto v:adj[i]) st.insert(low[v]);
            cout << comps - 1 + st.size() << '\n';
        }
    }
    return 0;
}
