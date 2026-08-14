#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],st[N*4],lazy[N*4],lazy2[N*4];

void build(ll id,ll l,ll r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    ll mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = max(st[id*2],st[id*2+1]);
}

void push(ll id)
{
    if(lazy2[id] != 0) {
        lazy2[id*2] = lazy2[id*2+1] = lazy2[id];
        st[id*2] = st[id*2+1] = st[id];
        lazy2[id] = 0;
    }
    st[id*2] += lazy[id];
    st[id*2+1] += lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
}

void update1(ll id,ll l,ll r,ll u,ll v,ll x)
{
   if(l > v || r < u) return;
    if(l == u && r == v) {
        st[id] = x;
        lazy2[id] = x;
        lazy[id] = 0;
        return;
    }
    ll mid = (l+r)/2;
    push(id);
    update1(id*2,l,mid,u,v,x);
    update1(id*2+1,mid+1,r,u,v,x);
    st[id] = max(st[id*2],st[id*2+1]);
}

void update2(ll id,ll l,ll r,ll u,ll v,ll x)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id] += x;
        lazy[id] += x;
        return;
    }
    ll mid = (l+r)/2;
    push(id);
    update2(id*2,l,mid,u,v,x);
    update2(id*2+1,mid+1,r,u,v,x);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return -1e18;
    if(u <= l && r <= v) return st[id];
    push(id);
    ll mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1,1,n);
    while(q--) {
        ll u,l,r,x;
        cin >> u >> l >> r;
        if(u == 1) {
            cin >> x;
            update1(1,1,n,l,r,x);
        }
        if(u == 2) {
            cin >> x;
            update2(1,1,n,l,r,x);
        }
        if(u == 3) {
            cout << get(1,1,n,l,r) << '\n';
        }
    }
    return 0;
}