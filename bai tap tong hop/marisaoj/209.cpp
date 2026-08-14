#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q,a[MM],last[MM],ans[MM];
vector<pair<int,int>> adj[MM];
void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= q;i++) {
        int u,v;
        cin >> u >> v;
        adj[v].push_back({u,i});
    }
}

int st[MM*4];

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
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void solve()
{
    for(int i = 1;i <= n;i++) {

        update(1,1,n,last[ a[i] ],0);
        
        last[ a[i] ] = i;
        
        update(1,1,n,last[ a[i] ],1);

        for(auto u:adj[i]) {
            int id = u.se, v = u.fi;
            ans[id] = get(1,1,n,v,i);
        }

    }

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}