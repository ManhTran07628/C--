#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q;
ll a[MM];

struct Node
{
    ll sum,premax,sufmax,maxsum;
} st[MM * 4];

Node Merge(Node a,Node b)
{
    ll sum = a.sum + b.sum;
    ll premax = max(a.premax,a.sum + b.premax);
    ll sufmax = max(b.sufmax,b.sum + a.sufmax);
    ll maxsum = max({a.sufmax + b.premax,a.maxsum,b.maxsum});
    return {sum,premax,sufmax,maxsum};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = { a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

Node get(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return {0ll,-oo,-oo,-oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return Merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        cout << get(1,1,n,l,r).maxsum << '\n';
    }
    return 0;
}