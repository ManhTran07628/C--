#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,m;
ll st[MM * 4],lazy[MM * 4];


void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] += lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v,ll val)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += val;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = max(st[id*2],st[id*2+1]);
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return -oo;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
    for(int i = 1;i <= m;i++) {
        int a,b,c; cin >> a >> b >> c;
        update(1,1,n,a,b,c);
    }
    int q; cin >> q;
    while(q--) {
        int a,b; cin >> a >> b;
        cout << get(1,1,n,a,b) << '\n';
    }
    return 0;
}