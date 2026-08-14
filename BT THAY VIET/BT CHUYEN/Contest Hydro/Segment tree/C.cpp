#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,q,m,st[MM*4],lazy1[MM*4],lazy2[MM*4],a[MM];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[l];
        lazy1[id] = 1;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
    lazy1[id] = 1;
}
// lazy1 : tich lazy2 tong
void fix(int id,int l,int r)
{
    if(lazy1[id] == 1 && !lazy2[id]) return;
    st[id] = st[id] * lazy1[id] + lazy2[id] * (r-l+1);
    st[id] %= m;
    if(l != r) {
        lazy1[id*2] *= lazy1[id];
        lazy1[id*2+1] *= lazy1[id];
        lazy2[id*2] = lazy1[id] * lazy2[id*2] + lazy2[id];
        lazy2[id*2+1] = lazy1[id] * lazy2[id*2+1] + lazy2[id];

        lazy1[id*2] %= m;
        lazy1[id*2+1] %= m;
        lazy2[id*2] %= m;
        lazy2[id*2+1] %= m;
    } 
    lazy1[id] = 1;
    lazy2[id] = 0;
}

void update1(int id,int l,int r,int u,int v,int x)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy1[id] *= x;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update1(id*2,l,mid,u,v,x);
    update1(id*2+1,mid+1,r,u,v,x);
    st[id] = st[id*2] + st[id*2+1];
    st[id] %= m;
}

void update2(int id,int l,int r,int u,int v,int x)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy2[id] += x;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update2(id*2,l,mid,u,v,x);
    update2(id*2+1,mid+1,r,u,v,x);
    st[id] = st[id*2] + st[id*2+1];
    st[id] %= m;
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    ll val = get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    val %= m;
    return val;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while(q--) {
        int t,x,y,k;
        cin >> t >> x >> y;
        if(t == 1) {
            cin >> k;
            update1(1,1,n,x,y,k);
        }
        else if(t == 2) {
            cin >> k;
            update2(1,1,n,x,y,k);
        }
        else cout << get(1,1,n,x,y) << '\n';
    }
    return 0;
}