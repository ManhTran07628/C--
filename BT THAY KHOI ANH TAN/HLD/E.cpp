#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,m,t[MM],num[MM],head[MM],heavy[MM],h[MM],timeDFS = 0,par[MM],tour[MM];
vector<int> adj[MM];

int dfs(int u)
{
    int cur_sz = 1, max_sz = 0;
    for(auto v:adj[u]) {
        if(v == par[u]) continue;
        par[v] = u;
        h[v] = h[u] + 1;
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
    tour[timeDFS] = u;
    if(heavy[u]) 
        decompose(heavy[u],H);
    
    for(auto v:adj[u]) {
        if(v != par[u] && v != heavy[u]) 
            decompose(v,v);
    }
}

struct Segtree
{
    vector<int> st[MM * 4];

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id].push_back(t[ tour[l] ]);
            return;
        }
        int mid = (l + r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        for(auto v:st[id*2]) st[id].push_back(v);
        for(auto v:st[id*2+1]) st[id].push_back(v);
        sort(st[id].begin(),st[id].end());
    }

    int get(int id,int l,int r,int u,int v,int val)
    {
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) {
            int pos = lower_bound(st[id].begin(),st[id].end(),val) - st[id].begin();
            if(pos == st[id].size()) return 0;
            if(st[id][pos] == val) return 1;
            return 0;
        }
        int mid = (l + r) / 2;
        return get(id*2,l,mid,u,v,val) | get(id*2+1,mid+1,r,u,v,val);
    }
} st;

int query(int a,int b,int c)
{
    while(head[a] != head[b]) {
        if(h[ head[a] ] < h[ head[b] ]) swap(a,b);
        int val = st.get(1,1,n,num[ head[a] ],num[a],c);
        if(val == 1) return 1;
        a = par[ head[a] ];
    }

    if(num[a] > num[b]) swap(a,b);
    int val = st.get(1,1,n,num[a],num[b],c);
    if(val == 1) return 1;
    return 0;
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
    for(int i = 1;i <= n;i++) cin >> t[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    decompose(1,1);
    st.build(1,1,n);
    while(m--) {
        int a,b,c; cin >> a >> b >> c;
        cout << query(a,b,c);
        // cout << 36 << ' '
    }
    return 0;
}