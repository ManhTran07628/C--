#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
ll st[MM*4],a[MM],n,q,stv[MM*4];


void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[l];
        stv[id] = max(0ll,a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
    stv[id] = max(stv[id*2],st[id*2]+stv[id*2+1]);
}

void update(int id,int l,int r,int pos,ll val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = val;
        stv[id] = max(0ll,val);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = st[id*2] + st[id*2+1];
    stv[id] = max(stv[id*2],st[id*2]+stv[id*2+1]);
}

pair<ll,ll> get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {0,0};
    if(u <= l && r <= v) return {st[id],stv[id]};
    int mid = (l+r)/2;
    pair<ll,ll> left = get(id*2,l,mid,u,v);
    pair<ll,ll> right = get(id*2+1,mid+1,r,u,v);
    ll sum = left.fi + right.fi;
    ll prefix_max = max(left.se,left.fi + right.se);
    return {sum,prefix_max};
}

void solve()
{
    build(1,1,n);
    // cout << get(1,1,n,2,5);
    while(q--) {
        ll t,l,r;
        cin >> t >> l >> r;
        if(t == 1) {
            update(1,1,n,l,r);
        }
        else {
            cout << get(1,1,n,l,r).se << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}