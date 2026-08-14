#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e5 + 7;
int n,m;
ll a[MM];
struct QR{int type,x,y,w,k;} qr[MM];

namespace subtask1
{
    void solve()
    {
        for(int i = 1;i <= m;i++) {
            if(qr[i].type == 1) {
                ll sum = 0;
                for(int j = qr[i].x;j <= qr[i].y;j++) {
                    sum += a[j];
                }
                cout << sum << '\n';
            }
            if(qr[i].type == 2) {
                for(int j = qr[i].x;j <= qr[i].y;j++) 
                    a[j] %= qr[i].w;
            }
            else if(qr[i].type == 3) a[ qr[i].x ] = qr[i].k;
        }
    }
}

namespace subtask23
{
    bool checksub()
    {
        for(int i = 1;i <= m;i++) {
            if(qr[i].type == 2) return 0;
        }
        return 1;
    }

    struct Node{ll max,pos,sum;} st[MM * 4];

    Node Merge(Node x,Node y)
    {
        ll sum = x.sum + y.sum;
        ll Max = max(x.max,y.max);
        ll pos = 0;
        if(x.max == Max) pos = x.pos;
        else pos = y.pos;
        return {Max,pos,sum};
    }

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = {a[l],l,a[l]};
            return;
        }
        int mid = (l + r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = Merge(st[id*2],st[id*2+1]);
    }

    void update(int id,int l,int r,int pos,ll k)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id].max = k;
            st[id].sum = k;
            return;
        }
        int mid = (l + r) / 2;
        update(id*2,l,mid,pos,k);
        update(id*2+1,mid+1,r,pos,k);
        st[id] = Merge(st[id*2],st[id*2+1]);
    }

    Node get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return {-oo,0,0};
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return Merge(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }

    void solve()
    {
        build(1,1,n);
        for(int i = 1;i <= m;i++) {
            if(qr[i].type == 1) {
                cout << get(1,1,n,qr[i].x,qr[i].y).sum << '\n';
            }
            if(qr[i].type == 2) {
                Node p = get(1,1,n,qr[i].x,qr[i].y);
                while(p.max >= qr[i].w) {
                    ll new_val = p.max % qr[i].w;
                    update(1,1,n,p.pos,new_val);
                    p = get(1,1,n,qr[i].x,qr[i].y);
                    // for(int i = 1;i <= n;i++) cout << get(1,1,n,i,i).sum << ' '; cout << '\n';
                }
            }
            else if(qr[i].type == 3) update(1,1,n,qr[i].x,qr[i].k);
        }

        // for(int i = 1;i <= n;i++) cout << get(1,1,n,i,i).sum << ' ';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "GIANGSINH"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];

    for(int i = 1;i <= m;i++) {
        cin >> qr[i].type;
        if(qr[i].type == 1) {
            cin >> qr[i].x >> qr[i].y;
        }
        else if(qr[i].type == 2) {
            cin >> qr[i].x >> qr[i].y >> qr[i].w;
        }
        else if(qr[i].type == 3) {
            cin >> qr[i].x >> qr[i].k;
        }
    }
    subtask23::solve();

    return 0;
}