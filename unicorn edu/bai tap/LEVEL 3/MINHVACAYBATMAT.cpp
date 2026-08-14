#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e5 + 7;
int blockSize = 710;
int n,k,m,c[MM],in[MM],out[MM],timeDFS = 0,tour[MM];
int sz = 0,cnt[MM],rb[MM],cur_res = 0,ans[MM];
struct Update{int node,oval,nval;};
vector<Update> updquery;
struct QR{int L,R,cnt_upd,id;} qr[MM];
vector<int> adj[MM];


void dfs(int u,int par)
{
    in[u] = ++timeDFS;
    tour[timeDFS] = u;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    out[u] = timeDFS;
}

bool cmp(QR a,QR b)
{
    int pa = a.L / blockSize;
    int pb = b.L / blockSize;
    if(pa != pb) return pa < pb;
    pa = a.R / blockSize;
    pb = b.R / blockSize;
    if(pa != pb) return pa < pb;
    return a.cnt_upd < b.cnt_upd;
}

void update(int x,int val)
{
    if(val == -1) {
        if(--cnt[ c[x] ] == 0) cur_res--;
    }
    else {
        if(++cnt[ c[x] ] == 1) cur_res++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> m;
    blockSize = pow(n,2. / 3.);
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
        rb[i] = c[i];
    }
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);

    for(int i = 1;i <= m;i++) {
        int type,a,b; cin >> type >> a;
        if(type == 1) {
            cin >> b;
            updquery.push_back({a,rb[a],b});
            rb[a] = b;
        }
        else {
            qr[++sz] = {in[a],out[a],(int) updquery.size() - 1,sz};
        }
    }
    sort(qr+1,qr+sz+1,cmp);
    int t = -1, l = 1, r = 0;
    for(int i = 1;i <= sz;i++) {

        while(t < qr[i].cnt_upd) {
            t++;
            int node = updquery[t].node;
            if(l <= in[node] && in[node] <= r) {
                if(--cnt[ c[node] ] == 0) cur_res--;
                c[node] = updquery[t].nval;
                if(++cnt[ c[node] ] == 1) cur_res++;
            }
            else c[node] = updquery[t].nval;
        }

        while(t > qr[i].cnt_upd) {
            int node = updquery[t].node;
            if(l <= in[node] && in[node] <= r) {
                if(--cnt[ c[node] ] == 0) cur_res--;
                c[node] = updquery[t].oval;
                if(++cnt[ c[node] ] == 1) cur_res++;
            }
            else c[node] = updquery[t].oval;
            t--;
        }

        while(l < qr[i].L) update(tour[l++],-1);
        while(l > qr[i].L) update(tour[--l],1);
        while(r < qr[i].R) update(tour[++r],1);
        while(r > qr[i].R) update(tour[r--],-1);

        ans[ qr[i].id ] = cur_res;
    }

    for(int i = 1;i <= sz;i++) cout << ans[i] << '\n';

    return 0;
}