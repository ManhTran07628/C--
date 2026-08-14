#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 70 + 7;
int n,m;
ll dp[MM][MM][MM + 3],f[MM][MM];
vector<pii> adj[MM];

struct Node
{
    ll u,dist_u,len;
};

struct cmp{bool operator() (Node a,Node b){return a.dist_u > b.dist_u;}};

void dijkstra(int st)
{
    priority_queue<Node,vector<Node>,cmp> q;
    for(int i = 1;i <= n;i++) {
        for(int k = 1;k <= n;k++)
            dp[st][i][k] = oo;
    }
    q.push({st,0,0});
    dp[st][st][0] = 0;
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int u = N.u, len = N.len;
        if(dp[st][u][len] < N.dist_u) continue;
        for(auto U:adj[u]) {
            int v = U.fi, w = U.se;
            if(dp[st][v][len + 1] > dp[st][u][len] + w) {
                dp[st][v][len + 1] = dp[st][u][len] + w;
                q.push({v,dp[st][v][len + 1],len + 1});
            }
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
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        ll u,v,t; cin >> u >> v >> t;
        if(f[u][v] == 0) f[u][v] = oo;
        f[u][v] = min(f[u][v],t);
    }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) {
            if(f[i][j] != oo && f[i][j] != 0) {
                adj[i].push_back({j,f[i][j]});
            }
        }

    for(int i = 1;i <= n;i++) {
        dijkstra(i);
    }

    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) 
            for(int k = 2;k <= n;k++) 
                dp[i][j][k] = min(dp[i][j][k - 1],dp[i][j][k]); 

    int k,q;
    cin >> k >> q;
    while(q--) {
        int x,y; cin >> x >> y;
        if(x == y) {
            cout << 0 << '\n';
            continue;
        }
        if(dp[x][y][min(k,n)] != oo) cout << dp[x][y][min(k,n)] << '\n';
        else cout << -1 << '\n';
    }
    return 0;
}