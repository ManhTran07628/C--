#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,q,a[MM],par[MM],state[MM];
ll st[MM * 4],lazy[MM * 4];
struct Query{int type,l,r,x,i;} qr[MM];

void build(int id,int l,int r)
{
    if(l == r) {
        st[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id] = st[id*2] + st[id*2+1];
}

void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] += lazy[id] * (r - l + 1);
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
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l + r) / 2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

int find_sets(int a)
{
    if(a == par[a]) return a;
    return par[a] = find_sets(par[a]);
}

void Unite(int a,int b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return;
    par[b] = a;
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
    for(int i = 1;i <= q;i++) par[i] = i;
    build(1,1,n);
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].type;
        if(qr[i].type == 1) {
            cin >> qr[i].l >> qr[i].r >> qr[i].x;
            update(1,1,n,qr[i].l,qr[i].r,qr[i].x);
        }
        if(qr[i].type == 2) {
            cin >> qr[i].i;

            Unite(qr[i].i,i);
            int j = find_sets(qr[i].i);
            state[j]++; state[j] %= 2;
            if(state[j]) update(1,1,n,qr[j].l,qr[j].r,-qr[j].x);
            if(!state[j]) update(1,1,n,qr[j].l,qr[j].r,qr[j].x);
        }
        if(qr[i].type == 3) {
            cin >> qr[i].l >> qr[i].r;
            cout << get(1,1,n,qr[i].l,qr[i].r) << '\n';
        }
    }
    // cout << par[5];
    return 0;
}