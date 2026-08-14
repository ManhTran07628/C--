#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e6 + 7;
int n,Q,B,r[MM],p[MM];

namespace subtask12
{
    pii st[MM * 4];
    
    pii Merge(pii a,pii b)
    {
        int val = min(a.fi,b.fi);
        if(val == a.fi) return a;
        return b;
    }

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = {0,l};
            return;
        }
        int mid = (l + r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = Merge(st[id*2],st[id*2+1]);
    }


    void update(int id,int l,int r,int pos,ll val)
    {
        if(l > pos || r < pos) return;
        if(l == r) {
            st[id].fi += val;
            return;
        }
        int mid = (l + r) / 2;
        update(id*2,l,mid,pos,val);
        update(id*2+1,mid+1,r,pos,val);
        st[id] = Merge(st[id*2],st[id*2+1]);
    }

    pii get(int id,int l,int r,int u,int v)
    {
        if(l > v || r < u) return {oo,0};
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return Merge(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
    }

    void solve()
    {
        build(1,1,n);
        for(int i = 1;i <= Q;i++) {
            while(p[i]--) {
                int pos = get(1,1,n,1,r[i]).se;
                update(1,1,n,pos,1);
            }
        }
        for(int i = 1;i <= n;i++) {
            cout << get(1,1,n,i,i).fi + B << ' ';
        }
    }
}

namespace subtask3
{
    ll c[MM];

    bool check(int x,int R,ll P)
    {
        ll need = 1ll * (R - x + 1) * c[x];
        for(int i = x;i <= R;i++) need -= c[i];
        return need <= P; 
    }

    void process(int L,int R,int Rend,ll P)
    {
        int x = R;
        while(L <= R) {
            int mid = (L + R) / 2;
            if(check(mid,Rend,P)) {
                x = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }

        ll new_h = P;
        for(int i = x;i <= Rend;i++) new_h += c[i];
        ll r = new_h % (Rend - x + 1);
        
        for(int i = x;i <= Rend;i++) {
            c[i] = new_h / (Rend - x + 1);;
            if(r > 0) {
                c[i]++;
                r--;
            }
        }
    }

    void solve()
    {
        for(int q = 1;q <= Q;q++) {
            process(1,r[q],r[q],p[q]);
        }
        for(int i = 1;i <= n;i++) cout << c[i] + B << ' ';
    }
}

namespace subtask4
{
    struct Segtree
    {
        ll st[MM * 4] = {}, lazy[MM * 4] = {};

        void fix(int id,int l,int r)
        {
            if(!lazy[id]) return;
            st[id] = lazy[id] * (r - l + 1);
            if(l != r) {
                lazy[id*2] = lazy[id];
                lazy[id*2+1] = lazy[id];
            }
            lazy[id] = 0;
        }

        void update(int id,int l,int r,int u,int v,ll val)
        {
            fix(id,l,r);
            if(l > v || r < u) return;
            if(u <= l && r <= v) {
                lazy[id] = val;
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
    } g;

    bool check(int x,ll Rend,ll p)
    {
        ll need = g.get(1,1,n,x,x) * (Rend - x + 1) - g.get(1,1,n,x,Rend);
        return need <= p;
    }

    void bins(int L,int R,int Rend,ll p)
    {
        int x = R;
        while(L <= R) {
            int mid = (L + R) / 2;
            if(check(mid,Rend,p)) {
                x = mid;
                R = mid - 1;
            }
            else L = mid + 1;
        }

        ll new_h = g.get(1,1,n,x,Rend) + p;
        ll delta = (Rend - x + 1);
        ll r = new_h % delta;
        g.update(1,1,n,x,Rend,new_h / delta);
        if(r > 0) g.update(1,1,n,x,x + r - 1,new_h / delta + 1);
    }

    void solve()
    {
        for(int i = 1;i <= Q;i++) {
            bins(1,r[i],r[i],p[i]);
        }
        for(int i = 1;i <= n;i++) cout << g.get(1,1,n,i,i) + B << ' ';
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
    cin >> n >> Q >> B;
    for(int i = 1;i <= Q;i++) {
        cin >> r[i] >> p[i];
    }
    subtask4::solve();
    // if(*max_element(p + 1,p + Q + 1) == 1) subtask12::solve();
    // else subtask3::solve();
    return 0;
}