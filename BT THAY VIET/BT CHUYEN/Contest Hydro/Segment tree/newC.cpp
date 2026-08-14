#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],st[N*4],lazy[N*4];
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

void update(ll id,ll l,ll r,ll u,ll v,ll val)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += val;
        st[id] += val*(r-l+1);
        return;
    }
    ll mid = (l+r)/2;
    st[id*2] += lazy[id]*(mid-l+1);
    st[id*2+1] += lazy[id]*(r-mid);
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(ll id,ll l,ll r,ll u,ll v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    ll mid = (l+r)/2;
    st[id*2] += lazy[id]*(mid-l+1);
    st[id*2+1] += lazy[id]*(r-mid);
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
    return(get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v));
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
        ll u;
        cin >> u;
        if(u == 1) {
            ll x,y,k;
            cin >> x >> y >> k;
            update(1,1,n,x,y,k);
        }
        else {
            ll x;
            cin >> x;
            cout << get(1,1,n,x,x) << '\n';
        }
    }
    return 0;
}