#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll st[MM*4],a[MM],n,q;

void build(ll id,ll l,ll r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = min(st[id*2],st[id*2+1]);
}

void update(ll id,ll l,ll r,ll i,ll x)
{
    if(i < l || r < i) return;
    if(l == r) {
        st[id] += x;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,i,x);
    update(id*2+1,mid+1,r,i,x);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return oo;
    if(l >= u && r <= v) {
        return st[id];
    }
    ll mid = (l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
        ll t,u,v;
        cin >> t >> u >> v;
        if(t == 1) update(1,1,n,u,v);
        else cout << get(1,1,n,u,v) << '\n';
    }
    return 0;
}