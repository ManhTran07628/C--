#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n,q;
int c[MM],num[MM],m = 0,tour[MM],lastpos[MM],en[MM];
vector<int> adj[MM];

void dfs(int u,int par)
{
    tour[++m] = u;
    num[u] = m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    en[u] = m;
}

int st[MM*4],lazy[MM*4];

// void fix(int id,int l,int r)
// {
//     if(!lazy[id]) return;
//     st[id] += lazy[id];
//     if(l != r) {
//         lazy[id*2] += lazy[id];
//         lazy[id*2+1] += lazy[id];
//     }
//     lazy[id] = 0;
// }

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
}

int get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

set<int> color[MM];

int QueryAdd(int s,int k)
{
    if(color[k].empty()) {
        color[k].insert( num[s] );
        update(1,1,n,num[s],1);
    }
    else {
        int firstpos =  
        if(*color[k].begin() != color[k].find(k))
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i <= n;i++) {
        color[ c[i] ].insert( num[i] );
    }
    for(int i = 1;i <= (int) *max_element(c+1,c+n+1);i++) {
        if(!color[i].empty()) {
            int first = *color[i].begin();
            update(1,1,n,first,1);
        }
    }

    while(q--) {

    }


    return 0;
}