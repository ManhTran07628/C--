#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
int n,q;
int ps[MM];

void init()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        char c;
        cin >> c;
        if(c == '*') ps[i] = ps[i-1] + 1;
        else ps[i] = ps[i-1] - 1;
        // cout << ps[i] << ' ';
    }
    // cout << '\n';
}

struct Node{int firstval,maxval;} st[MM*4];

Node Merge(Node a,Node b)
{
    return {min(a.firstval,b.firstval),max(a.maxval,b.maxval)};
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {ps[l],ps[l]};
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

ll getpos(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return oo;
    if(l == r) return l;
    int mid = (l+r)/2;
    ll memo = oo;
    if(st[id*2].firstval - ps[u-1] < 0) memo = getpos(id*2,l,mid,u,v);
    if(memo != oo) return memo;
    if(st[id*2+1].firstval - ps[u-1] < 0) memo = getpos(id*2+1,mid+1,r,u,v);
    return memo;
}

ll getmax(int id,int l,int r,int u,int v)
{
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id].maxval - ps[u-1];
    int mid = (l+r)/2;
    return max(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid+1,r,u,v));
}

void solve()
{
    build(1,1,n);
    while(q--) {
        int l,r;
        cin >> l >> r;
        ll firstpos = getpos(1,1,n,l,r);
        // cout << firstpos << '\n';
        cout << getmax(1,1,n,l,(firstpos == oo ? r : firstpos)) + 1 + (firstpos != oo) << '\n';
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}