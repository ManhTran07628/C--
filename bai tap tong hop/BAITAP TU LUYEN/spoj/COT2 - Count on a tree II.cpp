#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
const int LOG = 17;
const int blockSize = 320;
int n,m;
ll val[MM];
int in[MM],out[MM],timeDFS = 0,up[MM][LOG + 1];
int h[MM],tour[MM * 2],vis[MM],cntcolor[MM],cur_res = 0,ans[MM];
vector<int> adj[MM];
struct dl{int l,r,id,lck;} qr[MM];

void dfs(int u)
{
    in[u] = ++timeDFS;
    tour[timeDFS] = u;
    for(auto v:adj[u]) {
        if(up[u][0] == v) continue;
        up[v][0] = u;
        h[v] = h[u] + 1;
        dfs(v);
    }
    out[u] = ++timeDFS;
    tour[timeDFS] = u;
}

void compress_cord()
{
    vector<ll> v;
    for(int i = 1;i <= n;i++) v.push_back(val[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i <= n;i++) {
        val[i] = lower_bound(v.begin(),v.end(),val[i]) - v.begin();
    }
}

bool cmp(dl a,dl b)
{
    int pa = a.l / blockSize;
    int pb = b.l / blockSize;
    if(pa != pb) return pa < pb;
    return a.r < b.r;
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

void update(int u)
{
    if(vis[u]) {
        if(--cntcolor[ val[u] ] == 0) cur_res--;
    }
    else {
        if(++cntcolor[ val[u] ] == 1) cur_res++;
    }
    vis[u] ^= 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> val[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    compress_cord();
    up[1][0] = 1;
    for(int j = 1;j <= LOG;j++)
        for(int i = 1;i <= n;i++)
            up[i][j] = up[ up[i][j-1] ][j-1];

    for(int i = 1;i <= m;i++) {
        int u,v; cin >> u >> v;
        if(in[u] >= in[v]) swap(u,v);
        int lck = LCK(u,v);
        if(u == lck) {
            qr[i].l = in[u];
            qr[i].r = in[v];
        }
        else {
            qr[i].l = out[u];
            qr[i].r = in[v];
            qr[i].lck = lck;
        }
        qr[i].id = i;
    }
    sort(qr+1,qr+m+1,cmp);
    int l = 1, r = 0;
    for(int i = 1;i <= m;i++) {
        while(l < qr[i].l) update(tour[l++]);
        while(l > qr[i].l) update(tour[--l]);
        while(r < qr[i].r) update(tour[++r]);
        while(r > qr[i].r) update(tour[r--]);

        if(qr[i].lck) update(qr[i].lck);
        ans[ qr[i].id ] = cur_res;
        if(qr[i].lck) update(qr[i].lck);
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << '\n';
    return 0;
}  