#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m;
ll x[MM];

struct Node{ll sum,prefix,suffix,Max;} st[MM * 4];

Node Merge(Node a,Node b)
{
    ll sum = a.sum + b.sum;
    ll prefix = max(a.sum + b.prefix,a.prefix);
    ll suffix = max(a.suffix + b.sum,b.suffix);
    ll Max = max({a.suffix + b.prefix,a.Max,b.Max});
    return {sum,prefix,suffix,Max};
}

void build(int id,int l,int r)
{
    if(l == r) {
        ll val = max(x[l],0ll);
        st[id] = {x[l],val,val,val};
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
        ll nxt = max(val,0ll);
        st[id] = {val,nxt,nxt,nxt};
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {0,-oo,-oo,-oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> x[i];
    build(1,1,n);
    while(m--) {
        int k,x; cin >> k >> x;
        update(1,1,n,k,x);
        cout << get(1,1,n,1,n).Max << '\n';
    }
    return 0;
}