#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n,q,a[MM];
struct Edge{int u,v; int x2,y2,x5,y5,zero;};
vector<Edge> edges;
vector<int> adj[MM];

int num[MM],h[MM],par[MM],head[MM],heavy[MM],timeDFS = 0;

int dfs(int u)
{
    int cur_sz = 1, max_sz = 0;
    for(auto v:adj[u]) {
        if(v == par[u]) continue;
        h[v] = h[u] + 1;
        par[v] = u;
        int child_sz = dfs(v);
        cur_sz += child_sz;
        if(child_sz > max_sz) {
            heavy[u] = v;
            max_sz = child_sz;
        }
    }
    return cur_sz;
}

void decompose(int u,int H)
{
    head[u] = H, num[u] = ++timeDFS;
    if(heavy[u])
        decompose(heavy[u],H);

    for(auto v:adj[u]) {
        if(v != par[u] && v != heavy[u])
            decompose(v,v);
    }
}

struct Node
{
    int x2,y2,x5,y5,zero;
} st[MM * 4];

Node Merge(Node a,Node b)
{
    return {a.x2 + b.x2, a.y2 + b.y2, a.x5 + b.x5, a.y5 + b.y5, a.zero | b.zero};
}

void update(int id,int l,int r,int pos,int x2,int y2,int x5,int y5,int zero)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {x2,y2,x5,y5,zero};
        return;
    }
    
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,x2,y2,x5,y5,zero);
    update(id*2+1,mid+1,r,pos,x2,y2,x5,y5,zero);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

Node get_query(int x,int y)
{
    Node res = {};
    while(head[x] != head[y]) {
        if(h[ head[x] ] < h[ head[y] ]) swap(x,y);

        Node ps = get(1,1,n,num[ head[x] ],num[x]);
        res = Merge(res,ps);

        x = par[ head[x] ];
    }

    if(h[x] > h[y]) swap(x,y);
    Node ps = get(1,1,n,num[x] + 1,num[y]);
    res = Merge(res,ps);   
    return res;
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
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        double w;
        cin >> u >> v >> w;
        
        int tu = round(10000 * w);

        int cnt2 = 0, cnt5 = 0;
        while(tu > 0 && tu % 2 == 0) {cnt2++; tu /= 2;}
        while(tu > 0 && tu % 5 == 0) {cnt5++; tu /= 5;}

        edges.push_back({u,v,cnt2,4,cnt5,4,tu == 0});

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);
    decompose(1,1);
    
    for(auto E:edges) {
        int u = E.u, v = E.v;
        int child = (par[u] == v ? u : v);
        update(1,1,n,num[child],E.x2,E.y2,E.x5,E.y5,E.zero);
    }

    while(q--) {
        int x,y; cin >> x >> y;
        Node val = get_query(x,y);

        int tu = a[x];
        int cnt2 = 0, cnt5 = 0;
        while(tu > 0 && tu % 2 == 0) {cnt2++; tu /= 2;}
        while(tu > 0 && tu % 5 == 0) {cnt5++; tu /= 5;}

        if(val.zero == 1 || tu == 0) {cout << "Yes" << '\n'; continue;}
        if(val.x2 - val.y2 + cnt2 >= 0 && val.x5 - val.y5 + cnt5 >= 0) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }

    return 0;
}