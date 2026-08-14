#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (int) 1e9
#define pii pair<int,int>
const int MM = 2e5+7;
int n,k;
vector<int> adj[MM];

void init()
{
    cin >> n >> k;
    for(int i = 2;i <= n;i++) {
        int u = i,v;
        cin >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
}

namespace subtask1
{
    int vis[MM],comps = 0,par[MM];

    void d1(int u)
    {
        for(auto v:adj[u]) {
            if(v == par[u]) continue;
            par[v] = u;
            d1(v);
        }
    }

    void dfs(int u)
    {
        if(!vis[u]) {
            comps++;
            vis[u] = 1;
        }
        for(auto v:adj[u]) {
            if(v == par[u]) continue;
            dfs(v);
        }
    }

    void solve()
    {
        d1(1);
        while(k--) {
            int t;
            cin >> t;
            for(int i = 1;i <= t;i++) {
                int u;
                cin >> u;
                if(!vis[u]) dfs(u);
            }
            cout << comps << '\n';
            comps = 0;
            for(int i = 1;i <= n;i++) vis[i] = 0;

        }
    }
}

namespace subtask2
{
    int num[MM],out[MM],m = 0,h[MM];
    vector<pii> s;
    void dfs(int u,int par)
    {
        num[u] = ++m;
        for(auto v:adj[u]) {
            if(v == par) continue;
            h[v] = h[u] + 1;
            dfs(v,u);
        }
        out[u] = m;
    }

    int st[MM * 4],lazy[MM * 4];

    void fix(int id,int l,int r)
    {
        if(lazy[id] == oo) return;
        st[id] = lazy[id] * (r - l + 1);
        if(l != r) {
            lazy[id * 2] = lazy[id];
            lazy[id * 2 + 1] = lazy[id];
        }
        lazy[id] = oo;
    }

    void update(int id,int l,int r,int u,int v,int val)
    {
        fix(id,l,r);
        if(l > v || r < u) return;
        if(u <= l && r <= v) {
            lazy[id] = val;
            fix(id,l,r);
            return;
        }
        int mid = (l+r)/2;
        update(id*2,l,mid,u,v,val);
        update(id*2+1,mid+1,r,u,v,val);
        st[id] = st[id * 2] + st[id * 2 + 1];
    }

    ll get(int id,int l,int r,int u,int v)
    {
        fix(id,l,r);
        if(l > v || r < u) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l+r)/2;
        return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
    }


    void solve()
    {
        for(int i = 1;i < MM * 4;i++) lazy[i] = oo;
        dfs(1,0);
        while(k--) {
            int t;
            cin >> t;
            update(1,1,n,1,n,0);
            s.clear();
            int cnt = 0;
            for(int i = 1;i <= t;i++) {
                int x; cin >> x;
                s.push_back({h[x],x});
            }
            sort(s.begin(),s.end());
            for(auto u:s) {
                int x = u.se;
                // cout << x << ' ';
                ll val = get(1,1,n,num[x],out[x]);
                if(val == 0) {
                    cnt += (out[x] - num[x] + 1);
                    update(1,1,n,num[x],out[x],1);
                }
            }
            cout << cnt << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    subtask2::solve();
    // subtask1::solve();
    return 0;
}