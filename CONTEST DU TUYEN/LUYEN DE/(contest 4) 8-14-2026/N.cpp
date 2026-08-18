#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,q,a[MM];

struct Node{ll sum,prefix,suffix,Max;} st[MM * 4];
ll lazy[MM * 4];

Node Merge(Node a,Node b)
{
    ll sum = a.sum + b.sum;
    ll prefix = max(a.prefix,a.sum + b.prefix);
    ll suffix = max(b.suffix,a.suffix + b.sum);
    ll Max = max({a.Max,b.Max,a.suffix + b.prefix});
    return {sum,prefix,suffix,Max};
}

void build(int id,int l,int r)
{
    lazy[id] = oo;
    if(l == r) {
        st[id] = {a[l],a[l],a[l],a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void fix(int id,int l,int r)
{
    if(lazy[id] == oo) return;
    ll val = lazy[id] * (r - l + 1);

    st[id].sum = val;
    st[id].prefix = max(lazy[id],val);
    st[id].suffix = max(lazy[id],val);
    st[id].Max = max(lazy[id],val);

    if(l != r) {
        lazy[id * 2] = lazy[id];
        lazy[id * 2 + 1] = lazy[id];
    }
    lazy[id] = oo;
}

void update(int id,int l,int r,int u,int v,ll val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] = val;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {0,-oo,-oo,-oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
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
    build(1,1,n);
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int l,r,v; cin >> l >> r >> v;
            update(1,1,n,l,r,v);
        }
        else {
            int l,r; cin >> l >> r;
            Node val = get(1,1,n,l,r);
            cout << val.Max << '\n';
        }
    }
    return 0;
}