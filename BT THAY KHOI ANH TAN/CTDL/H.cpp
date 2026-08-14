#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 3e5+7;
const int lim = 101;
int n,q,a[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

bitset<lim> st[MM*4];
int lazy[MM*4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = bitset<lim>(1) << a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] | st[id*2+1];
}

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] = bitset<lim>(1) << lazy[id];
    if(l != r) {
        lazy[id*2] = lazy[id];
        lazy[id*2+1] = lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v,int val)
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
    st[id] = st[id*2] | st[id*2+1];
}

bitset<lim> get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return bitset<lim>(0);
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) | get(id*2+1,mid+1,r,u,v);
}

void solve()
{
    build(1,1,n);
    while(q--) {
        int t,l,r,x;
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> x;
            update(1,1,n,l,r,x);
        }
        else cout << get(1,1,n,l,r).count() << '\n';
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