#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,t,R[MM];

namespace subtask1
{
    void solve()
    {
        while(t--) {
            int pos = 0,X = 0;
            for(int i = 1;i <= n;i++) {
                if(R[i] > X) {
                    pos = i;
                    X = R[i];
                }
            }
            R[pos] = 0;
            cout << pos << '\n';
            int point = X / (n - 1), bonus = X % (n - 1);
            for(int i = 1;i <= n;i++) {
                if(i == pos) continue;
                R[i] += point;
                if(bonus > 0) {
                    R[i]++;
                    bonus--;
                }
            }
            // for(int i = 1;i <= n;i++) cout << r[i] << ' '; cout << '\n';
        }
    }
}

namespace subtask2
{
    pair<ll,ll> st[MM * 4];
    ll lazy[MM * 4];

    pair<ll,ll> Merge(pair<ll,ll> a,pair<ll,ll> b)
    {
        if(a.fi >= b.fi) return a;
        return b;
    }

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = {R[l],l};
            return;
        }
        int mid = (l + r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = Merge(st[id*2],st[id*2+1]);
    }

    void fix(int id,int l,int r)
    {
        if(lazy[id] == 0) return;
        st[id].fi += lazy[id];
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
        st[id] = Merge(st[id*2],st[id*2+1]);
    }

    pair<ll,ll> get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l == r) return st[id];
        int mid = (l + r) / 2;
        pair<ll,ll> memo = {};
        if(st[id*2].fi >= st[id*2+1].fi) memo = get(id*2,l,mid,u,v);
        else memo = get(id*2+1,mid+1,r,u,v);
        return memo; 
    }

    void solve()
    {
        build(1,1,n);
        while(t--) {
            pair<ll,ll> A = get(1,1,n,1,n);
            ll X = A.fi, pos = A.se;
            cout << pos << '\n';
            ll point = X / (n - 1);
            update(1,1,n,pos,pos,-(X + point));
            update(1,1,n,1,n,point);
            ll bonus = X % (n - 1);
            if(bonus >= pos) {
                update(1,1,n,1,pos - 1,1);
                update(1,1,n,pos + 1,bonus + 1,1);
            }
            else update(1,1,n,1,bonus,1);
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
    cin >> n >> t;
    for(int i = 1;i <= n;i++) cin >> R[i];
    subtask2::solve();
    return 0;
}