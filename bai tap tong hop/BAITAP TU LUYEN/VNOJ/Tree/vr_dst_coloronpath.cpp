#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
const int blockSize = 320;
int n,q,c[MM],cnt[MM],ans[MM],vis[MM];
vector<int> adj[MM];
struct QR{int l,r,lca = 0,c,id;} qr[MM];

const int LOG = 17;
struct Tree
{
    int up[MM][LOG + 1],h[MM];
    int in[MM],out[MM],tour[MM],m = 0;

    void dfs(int u) {
        tour[++m] = u;
        in[u] = m;
        for(auto v:adj[u]) {
            if(v == up[u][0]) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
        tour[++m] = u;
        out[u] = m;
    }

    void process()
    {
        dfs(1);
        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i <= n;i++)
                up[i][j] = up[ up[i][j-1] ][j-1];
    }

    int LCK(int u,int v)
    {
        if(h[v] > h[u]) swap(u,v);
        for(int i = LOG;i >= 0;i--)
            if(h[ up[u][i] ] >= h[v]) 
                u = up[u][i];
        if(u == v) return u;
        for(int i = LOG;i >= 0;i--)
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        return up[u][0];
    }
};
Tree T;

bool cmp(QR a,QR b)
{
    int pa = a.l / blockSize;
    int pb = b.l / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
}

void update(int x)
{
    if(!vis[x]) cnt[ c[x] ]++;
    else cnt[ c[x] ]--;
    vis[x] ^= 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    T.process();
    for(int i = 1;i <= q;i++) {
        int a,b,c; cin >> a >> b >> c;
        if(T.in[a] > T.in[b]) swap(a,b);
        int lca = T.LCK(a,b);
        qr[i].c = c;
        qr[i].id = i;
        if(a == lca) {
            qr[i].l = T.in[a];
            qr[i].r = T.in[b];
        }
        else {
            qr[i].l = T.out[a];
            qr[i].r = T.in[b];
            qr[i].lca = lca;
        }
    }
    sort(qr+1,qr+q+1,cmp);
    int l = 1,r = 0;
    for(int i = 1;i <= q;i++) {
        while(l < qr[i].l) update(T.tour[l++]);
        while(l > qr[i].l) update(T.tour[--l]);
        while(r < qr[i].r) update(T.tour[++r]);
        while(r > qr[i].r) update(T.tour[r--]);

        if(qr[i].lca) update(qr[i].lca);
        ans[ qr[i].id ] = (cnt[ qr[i].c ] > 0);
        if(qr[i].lca) update(qr[i].lca);
    }
    for(int i = 1;i <= q;i++) cout << ans[i]; 
    return 0;
}