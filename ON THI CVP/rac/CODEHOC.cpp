#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
const int MM = 5e5+7;
int n,q;
ll p[MM];
struct Node{ll val,pos;} st[MM*4];

void readinput()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> p[i];
}

Node merge(Node a,Node b)
{
    if(a.val + a.pos < b.val + b.pos) return a;
    return b;
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {p[l],l};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,int val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {val,l};
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {oo,oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

void solve()
{
    build(1,1,n);
    while(q--) {
        ll t,k,x;
        cin >> t >> k;
        if(t == 2) {
            Node p1 = get(1,1,n,1,k), p2 = get(1,1,n,k,n);
            ll ans = min(p1.val + abs(p1.pos - k),p2.val + abs(p2.pos - k));
            cout << ans << '\n';
            // cout << p1.val << ' ' << p1.pos << ' ' << p2.val << ' ' << p2.pos << '\n';
        }
        else {
            cin >> x;
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