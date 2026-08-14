#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e5+7;
int n,q,a[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

struct Node{ll pf,sf,sum,Max;} st[MM*4];
ll lazy[MM*4];

Node Merge(Node a,Node b)
{
    ll pf = max(a.sum + b.pf,a.pf);
    ll sf = max(a.sf + b.sum,b.sf);
    ll sum = a.sum + b.sum;
    ll Max = max({a.Max,b.Max,a.sf + b.pf});
    return {pf,sf,sum,Max};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l],a[l],a[l],max(0,a[l])};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void fix(int id,int l,int r)
{
    if(lazy[id] == oo) return;
    ll sum = 1ll * lazy[id] * (r-l+1);
    ll pf = max(lazy[id],sum);
    ll sf = max(lazy[id],sum);
    ll Max = max({sum,pf,sf,0ll});
    st[id] = {pf,sf,sum,Max};

    if(l != r) {
        lazy[id*2] = lazy[id];
        lazy[id*2+1] = lazy[id];
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
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {};
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return Merge(get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v));
}

void solve()
{
    for(int i = 1;i < MM*4;i++) lazy[i] = oo;
    build(1,1,n);
    while(q--) {
        int t,l,r,x;
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> x;
            update(1,1,n,l,r,x);
        }
        else cout << get(1,1,n,l,r).Max << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}