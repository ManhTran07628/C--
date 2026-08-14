#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e5+7;
ll n,M,q,a[MM];

void readinput()
{
    cin >> n >> M >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
}

namespace subtask1234
{
    ll st[MM*4][2],lazy[MM*4];
    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id][a[l]]++;
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id][0] = st[id*2][0] + st[id*2+1][0];
        st[id][1] = st[id*2][1] + st[id*2+1][1];
    }

    void fix(int id,int l,int r)
    {
        if(!lazy[id]) return;
        swap(st[id][0],st[id][1]);
        if(l != r) {
            lazy[id*2] = (lazy[id*2] + lazy[id]) % M;
            lazy[id*2+1] = (lazy[id*2+1] + lazy[id]) % M;
        }
        lazy[id] = 0;
    }

    void update(int id,int l,int r,int u,int v,ll c)
    {
        fix(id,l,r);
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            lazy[id] = (lazy[id] + c) % M;
            fix(id,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,v,c);
        update(id*2+1,mid+1,r,u,v,c);
        st[id][0] = st[id*2][0] + st[id*2+1][0];
        st[id][1] = st[id*2][1] + st[id*2+1][1];
    }

    int get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id][1];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }

    void solve()
    {
        build(1,1,n);
        while(q--) {
            ll t,L,R,c;
            cin >> t >> L >> R;
            if(t == 1) {
                cin >> c;
                update(1,1,n,L,R,c);
            }
            else {
                int d = get(1,1,n,L,R);
                if(d == 0 || d == R-L+1) cout << 0;
                else cout << 1;
                cout << '\n';
            }
        }
    }

}

namespace subtask5
{
    ll st[MM*4],lazy[MM*4];

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = a[l];
            return;
        }
        int mid = (l+r)/2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        if(st[id*2] != -1 && st[id*2] == st[id*2+1]) st[id] = st[id*2];
        else st[id] = -1;
    }

    void fix(int id,int l,int r)
    {
        if(!lazy[id]) return;
        if(st[id] != -1) st[id] = (st[id] + lazy[id]) % M;
        if(l != r) {
            lazy[id*2] = (lazy[id*2] + lazy[id]) % M;
            lazy[id*2+1] = (lazy[id*2+1] + lazy[id]) % M;
        }
        lazy[id] = 0;
    }

    void update(int id,int l,int r,int u,int v,ll c)
    {
        fix(id,l,r);
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            lazy[id] = (lazy[id] + c) % M;
            fix(id,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,v,c);
        update(id*2+1,mid+1,r,u,v,c);
        if(st[id*2] != -1 && st[id*2] == st[id*2+1]) st[id] = st[id*2];
        else st[id] = -1;
    }
    ll ok = -1;

    void get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(ok == -2) return;
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            if(ok == -1) ok = st[id];
            if(st[id] == -1) ok = -2;
            if(ok != st[id]) ok = -2;
            return;
        }   
        int mid = (l+r)/2;
        get(id*2,l,mid,u,v);
        get(id*2+1,mid+1,r,u,v);
    }

    void solve()
    {
        build(1,1,n);
        while(q--) {
            ll t,L,R,c;
            cin >> t >> L >> R;
            if(t == 1) {
                cin >> c;
                update(1,1,n,L,R,c % M);
            }
            else {
                ok = -1;
                get(1,1,n,L,R);
                cout << (ok == -2 ? 1 : 0) << '\n';
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    // subtask1234::solve();
    subtask5::solve();
    return 0;
}
