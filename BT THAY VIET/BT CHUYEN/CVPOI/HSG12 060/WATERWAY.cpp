#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e5 + 7;
int n,m,path[MM];
vector<int> adj[MM];

struct Edge{int u,v,id;};
vector<Edge> edges;

int num[MM],heavy[MM],head[MM],timeDFS = 0,h[MM],par[MM];

int dfs(int u)
{
    int cur_sz = 1, max_sz = 0;
    for(auto v:adj[u]) {
        if(v == par[u]) continue;
        h[v] = h[u] + 1;
        par[v] = u;
        int child_sz = dfs(v);
        cur_sz += child_sz;
        if(max_sz < child_sz) {
            heavy[u] = v;
            max_sz = child_sz;
        }
    }
    return cur_sz;
}

void decompose(int u,int H)
{
    num[u] = ++timeDFS; head[u] = H;
    if(heavy[u])
        decompose(heavy[u],H);

    for(auto v:adj[u]) {
        if(v != par[u] && v != heavy[u]) 
            decompose(v,v);
    }
}

int st[MM * 4];
void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] += val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void update_qr(int x)
{
    int node = path[x];
    update(1,1,n,num[node],-1);
}

int get_qr(int y)
{
    int res = 0;
    while(head[1] != head[y]) {
        res += get(1,1,n,num[ head[y] ],num[y]);
        y = par[ head[y] ];
    }
    res += get(1,1,n,2,num[y]);
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
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u,v,i});
    }
    
    dfs(1);
    decompose(1,1);

    for(auto E:edges) {
        int u = E.u, v = E.v, id = E.id;
        int child = (par[v] == u ? v : u);
        path[id] = child;
    }

    for(int i = 2;i <= n;i++) update(1,1,n,i,1); 

    cin >> m;
    for(int t = 1;t <= m + n - 1;t++) {
        char type; int x;
        cin >> type >> x;
        if(type == 'R') update_qr(x);
        else cout << get_qr(x) << '\n';
    }
    return 0;
}