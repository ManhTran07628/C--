#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n,q,a[MM];
pii st[MM * 4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l] + l,a[l] - l};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = {min(st[id*2].fi, st[id*2+1].fi), min(st[id*2].se, st[id*2+1].se)};
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {val + l,val - l};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = {min(st[id*2].fi, st[id*2+1].fi), min(st[id*2].se, st[id*2+1].se)};
}

pii get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {oo,oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    pii left = get(id*2,l,mid,u,v);
    pii right = get(id*2+1,mid+1,r,u,v);
    return {min(left.fi, right.fi), min(left.se, right.se)};
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int k,x; cin >> k >> x;
            update(1,1,n,k,x);
            // a[k] = x;
        }
        else {
            int k; cin >> k;
            ll left = get(1,1,n,1,k).se;
            ll right = get(1,1,n,k+1,n).fi;
            ll res = min(right - k,left + k);
            cout << res << '\n';
        }
    }
    return 0;
}