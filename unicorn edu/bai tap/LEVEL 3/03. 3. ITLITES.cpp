#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int> 
const int MM = 1e6 + 7;
int n,m;
pii st[MM * 4];
int lazy[MM * 4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {0,1};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = {st[id*2].fi + st[id*2+1].fi,st[id*2].se + st[id*2+1].se};
}

void fix(int id,int l,int r)
{
    lazy[id] %= 2;
    if(!lazy[id]) return;
    int x = st[id].se;
    st[id].se = (r - l + 1) - x;
    st[id].fi = (r - l + 1) - st[id].se;
    // cout << l << ' ' << r << ' ' << (r - l + 1) << ' ' << st[id].se << '\n';
    if(l != r) {
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id]++;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id] = {st[id*2].fi + st[id*2+1].fi,st[id*2].se + st[id*2+1].se};
}

int get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id].fi;
    int mid = (l + r) / 2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    build(1,1,n);
    // cout << get(1,1,n,3,4) << '\n';
    while(m--) {
        int type,s,e; cin >> type >> s >> e;
        if(type == 0) update(1,1,n,s,e);
        else cout << get(1,1,n,s,e) << '\n';
    }
    return 0;
}