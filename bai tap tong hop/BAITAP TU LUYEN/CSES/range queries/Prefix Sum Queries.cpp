#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,q;
ll a[MM];
struct Node{ll sum,prefix,Max;} st[MM * 4];

Node Merge(Node a, Node b)
{
    ll sum = a.sum + b.sum;
    ll prefix = max(a.sum + b.prefix,a.prefix);
    ll Max = max({a.Max, b.Max, prefix});
    return {sum, prefix, Max};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l],a[l],max(0ll,a[l])};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void update(int id,int l,int r,int pos,ll val)
{
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id] = {val,val,max(0ll,val)};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    // cout << get(1,1,n,4,5).sum << ' ' << get(1,1,n,6,6).prefix << '\n';
    // cout << get(1,1,n,1,3).sum << ' ' << get(1,1,n,4,6).prefix << '\n';
    // cout << get(1,1,n,1,6).Max;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int k,u; cin >> k >> u;
            update(1,1,n,k,u);
        }
        else {
            int l,r; cin >> l >> r;
            cout << max(0ll,get(1,1,n,l,r).prefix) << '\n';
        }
    }
    return 0;
}