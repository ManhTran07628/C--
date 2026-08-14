#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
const int MM = 5e5+7;
int n,q;
ll p[MM];
struct Node{ll val,pos;} st1[MM*4],st2[MM*4];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> p[i];
}

Node merge(Node a,Node b)
{
    if(a.val < b.val) return a;
    return b;
}

void build(int id,int l,int r)
{
    if(l == r) {
        st1[id] = {p[l] + l,l};
        st2[id] = {p[l] - l,n-l+1};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st1[id] = merge(st1[id*2],st1[id*2+1]);
    st2[id] = merge(st2[id*2],st2[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st1[id] = {val + l,l};
        st2[id] = {val - l,n-l+1};
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st1[id] = merge(st1[id*2],st1[id*2+1]);
    st2[id] = merge(st2[id*2],st2[id*2+1]);
}

Node get1(int id,int l,int r,int u,int v)
{
    if(u > v) return {oo,oo};
    if(l > v || r < u) return {oo,oo};
    if(u <= l && r <= v) return st1[id];
    int mid = (l+r)/2;
    return merge(get1(id*2,l,mid,u,v),get1(id*2+1,mid+1,r,u,v));
}

Node get2(int id,int l,int r,int u,int v)
{
    if(u > v) return {oo,oo};
    if(l > v || r < u) return {oo,oo};
    if(u <= l && r <= v) return st2[id];
    int mid = (l+r)/2;
    return merge(get2(id*2,l,mid,u,v),get2(id*2+1,mid+1,r,u,v));
}

void solve()
{
    build(1,1,n);
    while(q--) {
        ll t,k,x;
        cin >> t >> k;
        if(t == 2) {
            Node p1 = get2(1,1,n,1,k-1), p2 = get1(1,1,n,k+1,n);
            ll ans = min({p1.val+k , p2.val-k ,p[k]});
            cout << ans << '\n';
        }
        else {
            cin >> x;
            p[k] = x;
            update(1,1,n,k,x);
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