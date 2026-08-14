#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n,q;
ll a[MM],H;   

namespace subtask1
{
    void solve()
    {
        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int l,r,x; cin >> l >> r >> x;
                for(int i = l;i <= r;i++) a[i] += x;
            }
            else {
                int l,r; cin >> l >> r;
                int res = 0;
                for(int i = l;i <= r;i++)
                    res += (a[i] >= H);
                cout << res << '\n';
            }
        }
    }
}

struct Node{ll w,cnt,id;} st[MM * 4];

Node Merge(Node a,Node b)
{
    ll cnt = a.cnt + b.cnt;
    if(a.w > b.w) return {a.w,cnt,a.id};
    return {b.w,cnt,b.id};
}

ll lazy[MM * 4];

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id].w += lazy[id];
    if(l != r) {
        lazy[id*2] += lazy[id];
        lazy[id*2+1] += lazy[id];
    }
    lazy[id] = 0;
}

void build(int id,int l,int r)
{
    if(l == r) {
        st[id].w = a[l];
        st[id].id = l;
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void updaterange(int id,int l,int r,int u,int v,ll x)
{
    fix(id,l,r);
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        lazy[id] += x;
        fix(id,l,r);
        return;
    }
    int mid = (l + r) / 2;
    updaterange(id*2,l,mid,u,v,x);
    updaterange(id*2+1,mid+1,r,u,v,x);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

void updatepos(int id,int l,int r,int pos,ll v1,ll v2)
{
    fix(id,l,r);
    if(l > pos || r < pos) return;
    if(l == r) {
        st[id].cnt += v1;
        st[id].w = v2;
        return;
    }
    int mid = (l + r) / 2;
    updatepos(id*2,l,mid,pos,v1,v2);
    updatepos(id*2+1,mid+1,r,pos,v1,v2);
    st[id] = Merge(st[id*2],st[id*2+1]);
}

ll getval(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id].cnt;
    int mid = (l + r) / 2;
    return getval(id*2,l,mid,u,v) + getval(id*2+1,mid+1,r,u,v);
}

pii getpos(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(st[id].w < H) return {-oo,0};
    if(l > v || r < u) return {-oo,0};
    if(u <= l && r <= v) return {st[id].w,st[id].id};
    int mid = (l + r) / 2;
    pii L = getpos(id*2,l,mid,u,v), R = getpos(id*2+1,mid+1,r,u,v);
    if(L.fi > R.fi) return L;
    return R;
}

namespace sol
{
    void solve()
    {   
        build(1,1,n);

        // cout << getpos(1,1,n,1,n).fi << '\n';

        while(q--) {
            int type; cin >> type;
            if(type == 1) {
                int l,r,x; cin >> l >> r >> x;
                updaterange(1,1,n,l,r,x);
            }
            else {
                int l,r; cin >> l >> r;
                while(1) {
                    pii p = getpos(1,1,n,l,r);
                    ll w = p.fi, pos = p.se;
                    // cout << w << ' ' << pos << '\n';
                    if(w >= H) updatepos(1,1,n,pos,1,-oo);
                    else break;
                }

                cout << getval(1,1,n,l,r) << '\n';
            }
        }
    }
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
    cin >> n >> q >> H;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sol::solve();
    return 0;
}