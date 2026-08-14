#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int LOG = 18;
int n,m,q,p[MM],c[MM];
vector<int> adj[MM];
struct Edge{ll u,v,C;};
vector<Edge> edges;

struct LCA
{
    int up[MM][LOG + 1] = {}, h[MM] = {};
    void dfs(int u)
    {
        for(auto v:adj[u]) {
            if(up[u][0] == v) continue;
            up[v][0] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }

    void process()
    {
        dfs(1);
        up[1][0] = 1;
        for(int j = 1;j <= LOG;j++)
            for(int i = 1;i <= n;i++)
                up[i][j] = up[ up[i][j-1] ][j-1];
    }

    int LCK(int u,int v)
    {
        if(h[v] > h[u]) swap(u,v);
        for(int i = LOG;i >= 0;i--)
            if(h[ up[u][i] ] >= h[v])
                u = up[u][i];
        if(u == v) return u;
        for(int i = LOG;i >= 0;i--)
            if(up[u][i] != up[v][i])
                u = up[u][i], v = up[v][i];
        return up[u][0];
    };
} lca;

namespace subtask1
{
    vector<int> stat[MM];

    ll query(ll S,ll T,ll X,ll Y)
    {
        int lck = lca.LCK(S,T);
        vector<ll> need;
        while(S != lck) {
            for(auto cash:stat[S])
                need.push_back(cash);
            S = lca.up[S][0];
        }

        while(T != lck) {
            for(auto cash:stat[T])
                need.push_back(cash);
            T = lca.up[T][0];
        }

        sort(need.begin(),need.end());
        for(auto cash:need) {
            if(Y >= cash) Y -= cash;
            else X--;
        }
        if(X < 0) return -1;
        return X;
    }

    void solve()
    {
        for(int i = 1;i <= m;i++) {
            int u = edges[p[i] - 1].u;
            int v = edges[p[i] - 1].v;
            int child = (u == lca.up[v][0] ? v : u);
            stat[child].push_back(c[i]);
        }
        while(q--) {
            ll S,T,X,Y; cin >> S >> T >> X >> Y;
            cout << query(S,T,X,Y) << '\n';
        }
    }
}

namespace subtask2
{
    int head[MM] = {}, heavy[MM] = {}, tour[MM] = {}, num[MM] = {};
    int timeDFS = 0, value = 1;
    int stat[MM];

    int dfs(int u)
    {
        int cur_sz = 1, max_sz = 0;
        for(auto v:adj[u]) {
            if(lca.up[u][0] == v) continue;
            int child_sz = dfs(v);
            cur_sz += child_sz;
            if(max_sz < child_sz) {
                heavy[u] = v;
                max_sz = child_sz;
            }
        }
        return cur_sz;
    }

    void decompose(int u,int H)
    {
        num[u] = ++timeDFS; tour[timeDFS] = u;
        head[u] = H;
        if(heavy[u]) decompose(heavy[u],H);

        for(auto v:adj[u]) {
            if(lca.up[u][0] != v && v != heavy[u]) 
                decompose(v,v);
        }
    }

    struct SegTree
    {
        ll st[MM * 4] = {};
        
        void update(int id,int l,int r,int pos,int val)
        {
            if(l > pos || r < pos) return;
            if(l == r) {
                st[id] += val;
                return;
            }
            int mid = (l + r) / 2;
            update(id*2,l,mid,pos,val);
            update(id*2+1,mid+1,r,pos,val);
            st[id] = st[id*2] + st[id*2+1];
        }

        ll get(int id,int l,int r,int u,int v)
        {
            if(l > v || r < u) return 0;
            if(u <= l && r <= v) return st[id];
            int mid = (l + r) / 2;
            return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
        }
    } st;

    void update(int pos,int val)
    {
        st.update(1,1,n,num[pos],val);
    }

    ll query(ll S,ll T,ll X,ll Y)
    {
        ll cnt = 0;
        while(head[S] != head[T]) {
            if(lca.h[ head[S] ] > lca.h[ head[T] ]) swap(S,T);
            cnt += st.get(1,1,n,num[ head[T] ],num[T]);
            T = lca.up[ head[T] ][0];
        }

        if(num[S] > num[T]) swap(S,T);
        cnt += st.get(1,1,n,num[S] + 1,num[T]);

        cnt = cnt - Y / value;
        if(cnt <= 0) return X;
        if(cnt > X) return -1;
        return X - cnt;

    }

    void solve()
    {
        dfs(1);
        decompose(1,1);

        for(int i = 1;i <= m;i++) {
            auto E = edges[p[i] - 1];
            int u = E.u, v = E.v;
            value = c[i];
            int child = (lca.up[u][0] == v ? u : v);
            stat[child]++;
        }

        for(int i = 2;i <= n;i++) {
            update(i,stat[i]);
        }

        while(q--) {
            ll S,T,X,Y; cin >> S >> T >> X >> Y;
            cout << query(S,T,X,Y) << '\n';
            // cout << 35 << '\n';
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
    cin >> n >> m >> q;
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u,v});
    }

    lca.process();

    for(int i = 1;i <= m;i++) {
        cin >> p[i] >> c[i];
    }
    if(n <= 2e3 && m <= 2e3 && q <= 2e3) subtask1::solve();
    else subtask2::solve();
    return 0;
}