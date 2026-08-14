#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
int n,q,a[MM];
ll st[MM*4],lazy[MM*4],val[MM*4];
void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1]; 
}
// lazy1 : cong
// lazy2 : gan
void fix(int id,int l,int r)
{
    if(val[id] != 0) {
        st[id] = (r-l+1) * val[id];
        val[id*2] = val[id*2+1] = val[id];
        lazy[id*2] = lazy[id*2+1] = 0;
        val[id] = 0;
    }
    st[id] += (r-l+1) * lazy[id];
    lazy[id*2] += lazy[id];
    lazy[id*2+1] += lazy[id];
    lazy[id] = 0;
}

void update1(int id,int l,int r,int u,int v,ll va)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += va;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update1(id*2,l,mid,u,v,va);
    update1(id*2+1,mid+1,r,u,v,va);
    st[id] = st[id*2] + st[id*2+1];
}

void update2(int id,int l,int r,int u,int v,ll va)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        val[id] = va;
        lazy[id] = 0;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update2(id*2,l,mid,u,v,va);
    update2(id*2+1,mid+1,r,u,v,va);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void solve()
{
    readinput();
    build(1,1,n);
    while(q--) {
        ll t,A,B,X;
        cin >> t >> A >> B;
        if(t == 1) {
            cin >> X;
            update1(1,1,n,A,B,X);
        }
        else if(t == 2) {
            cin >> X;
            update2(1,1,n,A,B,X);
        }
        else {
            cout << get(1,1,n,A,B) << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}