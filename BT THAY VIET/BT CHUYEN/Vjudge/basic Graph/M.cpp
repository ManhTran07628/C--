#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 207;
int n,vis[MM],cnt = 0;
struct coord{int x,y,w;};
vector<coord> g;

void dfs(int u,int X1,int Y1)
{
    vis[u] = 1;
    int w = g[u].w;
    for(int v = 0;v < n;v++) {
        if(vis[v] || u == v) continue;
        int X2 = g[v].x, Y2 = g[v].y;
        int dist = (X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2);
        if(dist <= w*w) {
            cnt++;
            dfs(v,X2,Y2);
        }
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "moocast"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        int u,v,w;
        cin >> u >> v >> w;
        g.push_back({u,v,w});
    }
    int ans = 0;
    for(int i = 0;i < n;i++) {
        memset(vis,0,sizeof(vis));
        dfs(i,g[i].x,g[i].y);
        ans = max(ans,cnt+1); cnt = 0;
    }
    cout << ans;
    return 0;
}