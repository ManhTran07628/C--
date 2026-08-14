#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 3e5+7;
ll n,m,a[MM],st[MM*4];

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

void update(ll id,ll l,ll r,ll u,ll val)
{
    if(l > u || r < u) return;
    if(l == r) {
        st[id] = val;
        return;
    }
    ll mid = (l+r)/2;
    update(id*2,l,mid,u,val);
    update(id*2+1,mid+1,r,u,val);
    st[id] = min(st[id*2],st[id*2+1]);
}

ll getL(ll id,ll l,ll r,ll u,ll v,ll k)
{
    if(st[id] > k) return -1;
    if(r < u || l > v) return -1;

    if(l == r) return l;
    ll mid = (l+r)/2;
    ll res = -1;
    if(st[id*2] <= k) res = getL(id*2,l,mid,u,v,k);

    if(res == -1) res = getL(id*2+1,mid+1,r,u,v,k);
    return res;
}

ll getR(ll id,ll l,ll r,ll u,ll v,ll k)
{
    if(st[id] > k) return -1;
    if(l > v || r < u) return -1;

    if(l == r) return l;
    ll mid = (l+r)/2;
    ll res = -1;
    if(st[id*2+1] <= k) res = getR(id*2+1,mid+1,r,u,v,k);

    if(res == -1) res = getR(id*2,l,mid,u,v,k);
    return res;
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    build(1,1,n);
    while(m--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll pos,k;
            cin >> pos >> k;
            update(1,1,n,pos,k);
        }
        else {
            ll l,r,k;
            cin >> l >> r >> k;
            cout << getL(1,1,n,l,r,k) << ' ' << getR(1,1,n,l,r,k) << '\n';
        }
    }
    return 0;
}