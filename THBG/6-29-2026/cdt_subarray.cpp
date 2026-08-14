#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 5e5 + 7;
int n,q,a[MM];

struct Node
{
    ll sum,prefix,suffix,max_seg;
} st[MM * 4];

Node Merge(Node a,Node b)
{
    ll sum = a.sum + b.sum;
    ll prefix = max(a.prefix,a.sum + b.prefix);
    ll suffix = max(b.suffix,a.suffix + b.sum);
    ll max_seg = max({a.suffix + b.prefix,a.max_seg,b.max_seg});
    return {sum,prefix,suffix,max_seg};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l],a[l],a[l],a[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {0,-oo,-oo,-oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
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
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    while(q--) {
        int l,r; cin >> l >> r;
        cout << get(1,1,n,l,r).max_seg << '\n';
    }
    return 0;
}