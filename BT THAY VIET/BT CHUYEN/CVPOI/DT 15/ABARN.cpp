#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 1e5 + 7;
int n,m,c[MM],a[MM],b[MM],f[MM];

namespace subtask1
{
    vector<int> Point;

    bool check()
    {
        for(int i = 1;i <= n;i++) f[i] = 0;
        for(auto E:Point) {
            f[ a[E] ]++;
            f[ b[E] + 1 ]--;
        }
        for(int i = 1;i <= n;i++) {
            f[i] += f[i-1];
            if(f[i] > c[i]) return 0;
        }
        return 1;
    }
    
    int res = 0;
    void Try(int id)
    {
        if(id > m) {
            if(check()) res = max(res,(int) Point.size());
            return;
        }

        Point.push_back(id);
        Try(id + 1);
        Point.pop_back();

        Try(id + 1);
    }

    void solve()
    {
        Try(1);
        cout << res;
    }
}


namespace sol
{
    int st[MM * 4],lazy[MM * 4];

    void build(int id,int l,int r)
    {
        if(l == r) {
            st[id] = c[l];
            return;
        }
        int mid = (l + r) / 2;
        build(id*2,l,mid);
        build(id*2+1,mid+1,r);
        st[id] = min(st[id*2],st[id*2+1]);
    }

    void fix(int id,int l,int r)
    {
        if(!lazy[id]) return;
        st[id] -= lazy[id];
        if(l != r) {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
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
        int mid = (l + r) / 2;
        update(id*2,l,mid,u,v);
        update(id*2+1,mid+1,r,u,v);
        st[id] = min(st[id*2],st[id*2+1]);
    }

    int get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return oo;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r) / 2;
        return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
    }

    pair<int,int> p[MM];
    void solve()
    {
        build(1,1,n);
        for(int i = 1;i <= m;i++) p[i] = {a[i],b[i]};
        sort(p+1,p+m+1,[] (pair<int,int> a,pair<int,int> b){
            if(a.se != b.se) return a.se < b.se;
            return a.fi > b.fi;
        });
        int res = 0;
        for(int i = 1;i <= m;i++) {
            int l = p[i].fi, r = p[i].se;
            int minval = get(1,1,n,l,r);
            if(minval <= 0) continue;
            update(1,1,n,l,r);
            res++;
        }
        cout << res;
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= m;i++) cin >> a[i] >> b[i];
    // if(m <= 20) subtask1::solve();
    sol::solve();
    return 0;
}