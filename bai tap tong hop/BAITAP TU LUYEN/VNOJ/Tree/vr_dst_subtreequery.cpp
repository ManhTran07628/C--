#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,q,a[MM],in[MM],out[MM],tour[MM],m = 0;
vector<int> adj[MM];
ll st[MM * 4];

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void dfs(int u,int par)
{
    in[u] = ++m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    out[u] = m;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    for(int i = 1;i <= n;i++) 
        update(1,1,n,in[i],a[i]);
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int s,x; cin >> s >> x;
            update(1,1,n,in[s],x);
        }
        else {
            int s; cin >> s;
            cout << get(1,1,n,in[s],out[s]) << '\n';
        }
    }

    return 0;
}