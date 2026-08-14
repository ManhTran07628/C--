#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,q,st[MM*4],lazy[MM*4],a[MM];

void build(ll id,ll l,ll r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
}

void fix(ll id,ll l,ll r)
{
    if(!lazy[id]) return;
    st[id] += lazy[id]*(r-l+1);
    if(l != r) { // khong phai node cuoi
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(ll id,ll l,ll r,ll u,ll v,ll x)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += x;
        fix(id,l,r);
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v,x);
    update(id*2+1,mid+1,r,u,v,x);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) {
        return st[id];
    }
    ll mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1,1,n);
    while(q--) {
        int t,l,r,x;
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> x;
            update(1,1,n,l,r,x);
        }
        else cout << get(1,1,n,l,r) << '\n';
    }
    return 0;
}