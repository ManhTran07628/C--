#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
ll n,q,m,st[MM*4][2],lazy[MM*4];


void build(int id,int l,int r)
{
    if(l == r) {
        st[id][0]++;
        return;
    }
    int mid = (l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id][0] = st[id*2][0] + st[id*2+1][0];
}

// 0 - trang thai tat
// 1 - trang thai bat
void fix(int id,int l,int r)
{
    lazy[id] %= 2;
    if(!lazy[id]) return;
    swap(st[id][0],st[id][1]);
    if(l != r) {
        lazy[id*2]++;
        lazy[id*2+1]++;
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v)
{   
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id]++;
        fix(id,l,r);
        return;
    }
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v);
    update(id*2+1,mid+1,r,u,v);
    st[id][0] = st[id*2][0] + st[id*2+1][0];
    st[id][1] = st[id*2][1] + st[id*2+1][1];
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id][1];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    build(1,1,n);
    while(q--) {
        int t,a,b;
        cin >> t >> a >> b;
        if(!t) update(1,1,n,a,b);
        else cout << get(1,1,n,a,b) << '\n';
    }
    return 0;
}