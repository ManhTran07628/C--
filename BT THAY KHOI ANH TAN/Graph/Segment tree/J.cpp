#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3e5+7;
ll n,q,a[MM],st[MM*4],lazy[MM*4];

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

void fix(ll id,ll l,ll r)
{
    if(!lazy[id]) return;
    st[id] += lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(ll id,ll l,ll r,ll u,ll v,ll add)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += add;
        fix(id,l,r);
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,v,add);
    update(id*2+1,mid+1,r,u,v,add);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll getL(ll id,ll l,ll r,ll u,ll v,ll k)
{
    fix(id,l,r);
    if(l > v || r < u) return -1;
    if(st[id] > k) return -1;
    if(l == r) return l;
    ll res = -1;
    ll mid = (l+r)/2;
    res = getL(id*2,l,mid,u,v,k);
    if(res == -1) res = getL(id*2+1,mid+1,r,u,v,k);
    return res;
}

ll getR(ll id,ll l,ll r,ll u,ll v,ll k)
{
    fix(id,l,r);
    if(l > v || r < u) return -1;
    if(st[id] > k) return -1;
    if(l == r) return l;
    ll res = -1;
    ll mid = (l+r)/2;
    res = getR(id*2+1,mid+1,r,u,v,k);
    if(res == -1) res = getR(id*2,l,mid,u,v,k);
    return res;
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
        ll t,l,r,k;
        cin >> t >> l >> r >> k;
        if(t == 1) update(1,1,n,l,r,k);
        else {
            cout << getL(1,1,n,l,r,k) << ' ' << getR(1,1,n,l,r,k) << '\n';
        }
    }
    return 0;
}