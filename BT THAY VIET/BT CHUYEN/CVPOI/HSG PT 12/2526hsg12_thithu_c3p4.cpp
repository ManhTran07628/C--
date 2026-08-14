#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e6+7;
int n,t;
pii a[MM];
int st[MM * 4],lazy[MM * 4];

void fix(int id,int l,int r)
{
    if(lazy[id] == oo) return;
    st[id] = min(st[id],lazy[id]);
    if(l != r) {
        lazy[id*2] = min(lazy[id],lazy[id*2]);
        lazy[id*2+1] = min(lazy[id],lazy[id*2+1]);
    }
    lazy[id] = oo;
}

void update(int id,int l,int r,int u,int v,int val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] = min(lazy[id],val);
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
}

ll get(int id,int l,int r,int u,int v)
{
    if(u > v) return 0;
    fix(id,l,r);
    if(l > v || r < u) return oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i < MM * 4;i++) {
        lazy[i] = oo;
        st[i] = oo;
    }

    for(int i = 1;i <= n;i++) {
        int val = get(1,1,t,1,a[i].fi - 1);
        update(1,1,t,a[i].fi,a[i].se,val + 1);
    }
    ll res = get(1,1,t,t,t);
    cout << (res == oo ? -1 : res);
    return 0;
}