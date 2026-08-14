#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e4 + 7;
const int LOG = 17;
int n,q,h[MM],up[MM][LOG + 1],st[MM][LOG + 1];
vector<pii> adj[MM];

void dfs(int u)
{
    for(auto N:adj[u]) {
        int v = N.fi, w = N.se;
        if(v == up[u][0]) continue;
        up[v][0] = u;
        st[v][0] = w;
        h[v] = h[u] + 1;
        dfs(v);
    }
}


int LCK(int u,int v)
{
    if(h[v] > h[u]) swap(u,v);
    int val = 1;
    for(int j = LOG;j >= 0;j--)
        if(h[ up[u][j] ] >= h[v]) {
            val = max(val,st[u][j]);
            u = up[u][j];
        }

    if(u == v) return val;

    for(int j = LOG;j >= 0;j--)
        if(up[u][j] != up[v][j]) {
            val = max(val,max(st[u][j],st[v][j]));
            u = up[u][j], v = up[v][j];
        }
    val = max(val,max(st[v][0],st[u][0]));
    return val;
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
    cin >> n >> q;
    for(int i = 2;i <= n;i++) {
        int x,k; cin >> x >> k;
        adj[i].push_back({x,k});
        adj[x].push_back({i,k});
    }
    dfs(1);
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++) {
            up[i][j] = up[ up[i][j-1] ][j-1];
            st[i][j] = max(st[i][j-1],st[ up[i][j-1] ][j-1]);
        }
    while(q--) {
        int x,y; cin >> x >> y;
        if(x == y) cout << "NO" << '\n';
        else {
            int lck = LCK(x,y);
            if(lck == 2) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}
