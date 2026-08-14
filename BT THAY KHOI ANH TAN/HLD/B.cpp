#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int> 
const int MM = 2e5 + 7, LOG = 18;
int n,q,heavy[MM],head[MM],num[MM],m = 0,up[MM][LOG + 1],h[MM],tour[MM];
vector<int> adj[MM];

int dfs(int u,int par)
{
    int cur_sz = 1, max_sz = 0;
    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        int child_sz = dfs(v,u);
        up[v][0] = u;
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
    num[u] = ++m; head[u] = H;
    tour[m] = u;
    if(heavy[u]) 
        decompose(heavy[u],H);

    for(auto v:adj[u]) {
        if(v != up[u][0] && v != heavy[u])
            decompose(v,v);
    }
}

struct ST
{
    int st[MM * 4] = {};

    void update(int id,int l,int r,int pos)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id] ^= 1;
            return;
        }
        int mid = (l + r) / 2;
        update(id*2,l,mid,pos);
        update(id*2+1,mid+1,r,pos);
        st[id] = max(st[id*2],st[id*2+1]);
    }

    int get(int id,int l,int r,int u,int v)
    {
        if(st[id] == 0) return -1;
        if(l > v || r < u) return -1;
        if(l == r) return l;
        int mid = (l + r) / 2;
        int memo = get(id*2,l,mid,u,v);
        if(memo != -1) return memo;
        return get(id*2+1,mid+1,r,u,v);
    }
} st;

void update(int i)
{
    st.update(1,1,n,num[i]);
}

int get(int v)
{
    int res = -1, val = oo;
    while(head[v] != head[1]) {
        int cur = st.get(1,1,n,num[ head[v] ],num[v]);
        if(cur != -1 && val > h[ tour[cur] ]) {
            res = tour[cur];
            val = h[ tour[cur] ];
        }
        v = up[ head[v] ][0];
    }
    int cur = st.get(1,1,n,num[head[1]],num[v]); 
    if(cur != -1 && val > h[ tour[cur] ]) {
        res = tour[cur];
    }
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
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    decompose(1,1);

    while(q--) {
        int type,i; cin >> type >> i;
        if(type == 0) {
            update(i);
        }
        else {
            cout << get(i) << '\n';
        }
    }
    return 0;
}