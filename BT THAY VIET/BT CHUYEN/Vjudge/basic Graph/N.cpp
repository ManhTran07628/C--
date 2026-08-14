#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,m,vis[MM],X1 = oo,Y1 = 0,X2 = 0,Y2 = oo,ans = oo;
pair<int,int> C[MM];
vector<int> adj[MM];

void dfs(int u)
{
    int x = C[u].fi,y = C[u].se;
    X1 = min(x,X1); Y1 = max(y,Y1);
    X2 = max(x,X2); Y2 = min(y,Y2);
    vis[u] = 1;
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "fenceplan"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> C[i].fi >> C[i].se;
    }
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i <= n;i++) {
        if(!vis[i]) {
            dfs(i);
            int w = abs(X2-X1), h = abs(Y2-Y1);
            ans = min(ans,(w+h)*2);
            X1 = oo,Y1 = 0,X2 = 0,Y2 = oo;
        }
    }
    cout << ans;
    return 0;
}