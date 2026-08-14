#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
const int LOG = 18;
int n,q,up1[MM][LOG+1],up2[MM][LOG+1],a = 0,b = 0,cur_h = 0,h1[MM],h2[MM];
vector<int> adj[MM];

void readInput()
{
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
}

void dfs_ab(int u,int par,int &x)
{
    if(h1[u] > cur_h) {
        x = u;
        cur_h = h1[u];
    }
    for(auto v:adj[u]) {
        if(v != par) {
            h1[v] = h1[u] + 1;
            dfs_ab(v,u,x);
        }
    }
}

void diameter()
{
    dfs_ab(1,0,a);
    memset(h1,0,sizeof(h1));
    cur_h = 0;
    dfs_ab(a,0,b);
    memset(h1,0,sizeof(h1));
}

void dfs1(int u)
{
    for(auto v:adj[u]) {
        if(up1[u][0] != v) {
            up1[v][0] = u;
            h1[v] = h1[u] + 1;
            dfs1(v);
        }
    }
}

void dfs2(int u)
{
    for(auto v:adj[u]) {
        if(up2[u][0] != v) {
            up2[v][0] = u;
            h2[v] = h2[u] + 1;
            dfs2(v);
        }
    }
}

void process()
{
    dfs1(a);
    dfs2(b);
    // up1[a][0] = a;
    // up2[b][0] = b;
    for(int j = 1;j <= LOG;j++) {
        for(int i = 1;i <= n;i++) {
            up1[i][j] = up1[ up1[i][j-1] ][j-1];
            up2[i][j] = up2[ up2[i][j-1] ][j-1];
        }
    }
}

int find_ancestor(int u,int k,int t)
{
    int ancs = 0;
    for(int i = LOG;i >= 0;i--) {
        if(k >> i & 1) {
            if(t == 1) u = up1[u][i];
            else u = up2[u][i];
        }
    }
    return u;
}

void solve()
{
    diameter();
    process();
    while(q--) {
        int u,k;
        cin >> u >> k;
        int d = find_ancestor(u,k,1);
        if(d == 0) d = find_ancestor(u,k,2);
        if(d == 0) cout << -1 << '\n';
        else cout << d << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readInput();
    solve();
    return 0;
}