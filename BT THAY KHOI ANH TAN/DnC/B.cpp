#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 2e5 + 7;
int n,a[MM],lazy[MM * 4];
pii st[MM * 4];

pii Merge(pii a,pii b)
{
    int Min = min(a.fi,b.fi);
    if(Min == a.fi) return a;
    return b;
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l],l};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id].fi += lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void update(int id,int l,int r,int u,int v,int val)
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
    st[id] = Merge(st[id*2],st[id*2+1]);
}

pii get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {oo,0};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

ll dnc(int L,int R)
{
    if(L > R) return 0;
    if(L == R) {
        if(get(1,1,n,L,L).fi > 0) return 1;
        return 0;
    }
    // cout << R - L + 1 << ": ";
    // for(int i = L;i <= R;i++) get_min(1,1,n,);
    // get_min(1,1,n,L,R);
    
    pii Node = get(1,1,n,L,R);
    int Min = Node.fi;
    if(Min == 0) {
        int pos = Node.se;
        return dnc(L,pos - 1) + dnc(pos + 1,R);
    }

    update(1,1,n,L,R,-Min);
    Node = get(1,1,n,L,R);
    int pos = Node.se;
    return dnc(L,pos - 1) + dnc(pos + 1,R) + 1;
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
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    cout << dnc(1,n);
    // cout << find_pos(1,1,n,3,n);
    return 0;
}