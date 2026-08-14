#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 5e5 + 7;
int n,k,a[MM],bit[MM];
ll lazy[MM * 4];
pii st[MM * 4];
void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = {a[l],l};
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    if(st[id*2].fi > st[id*2+1].fi) st[id] = st[id*2+1];
    else st[id] = st[id*2];
}

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] = {st[id].fi + lazy[id],st[id].se};
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
    if(st[id*2].fi > st[id*2+1].fi) st[id] = st[id*2+1];
    else st[id] = st[id*2];
}

pii get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return {oo,oo};
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    pii left = get(id*2,l,mid,u,v);
    pii right = get(id*2+1,mid+1,r,u,v);
    if(left.fi > right.fi) return right;
    return left;
}

void updatebit(int x,int val)
{
    for(;x <= n;x += (x & -x)) bit[x] += val;
}

int getbit(int x)
{
    int res = 0;
    for(;x > 0;x -= (x & -x)) res += bit[x];
    return res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    build(1,1,n);
    int q; cin >> q;
    while(q--) {
        int type,l,r; cin >> type >> l >> r;
        if(type == 1) {
            int x; cin >> x;
            update(1,1,n,l,r,x);
        }
        else {
            pii query = get(1,1,n,l,r);
            while(query.fi <= k) {
                updatebit(query.se,1);
                update(1,1,n,query.se,query.se,oo);
                query = get(1,1,n,l,r);
            }
            cout << getbit(r) - getbit(l-1) << '\n';
        }
    }
    return 0;
}
