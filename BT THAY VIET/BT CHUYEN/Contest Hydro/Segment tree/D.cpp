#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,q,a[MM],st[MM*4],lazy1[MM*4],lazy2[MM*4];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = max(st[id*2],st[id*2+1]);
}

// lazy1 - gan   lazy2 - cong

void fix(int id,int l,int r,int t)
{
    if(!lazy1[id] && !lazy2[id]) return;
    if(t == 1) st[id] = lazy1[id];
    else st[id] += lazy2[id];
    if(l != r) {
        lazy1[id*2] = lazy1[id];
        lazy1[id*2+1] = lazy1[id];

        lazy2[id*2] += lazy2[id];
        lazy2[id*2+1] += lazy2[id];
    }
    lazy1[id] = 0;
    lazy2[id] = 0;
}

void update1(int id,int l,int r,int u,int v,int x)
{
    fix(id,l,r,1);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy1[id] = x;
        fix(id,l,r,1);
        return;
    }
    int mid = (l+r)/2;
    update1(id*2,l,mid,u,v,x);
    update1(id*2+1,mid+1,r,u,v,x);
    st[id] = max(st[id*2],st[id*2+1]);
}

void update2(int id,int l,int r,int u,int v,int x)
{
    fix(id,l,r,2);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy2[id] += x;
        fix(id,l,r,2);
        return;
    }
    int mid = (l+r)/2;
    update2(id*2,l,mid,u,v,x);
    update2(id*2+1,mid+1,r,u,v,x);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r,1);
    if(l > v || r < u) return -oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));

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
        int t,l,r,x;
        cin >> t >> l >> r;
        if(t == 1) {
            cin >> x;
            update1(1,1,n,l,r,x);
        }
        else if(t == 2) {
            cin >> x;
            update2(1,1,n,l,r,x);
        }
        else cout << get(1,1,n,l,r) << '\n';
    }
    return 0;
}