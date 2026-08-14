#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 2e9
#define pii pair<int,int> 
const int MM = 1e6 + 7;
int n,k,q,c[MM],A[MM],B[MM];

struct DSU
{
    struct Sn
    {
        int u,v,min_val;
        int is_tree;
        ll sumA = 0, sum_a;
    };
    vector<Sn> snapshot;

    int is_tree[MM] = {};

    int par[MM] = {}, sz[MM] = {}, minval[MM] = {};
    ll sum[MM] = {}, sum_total = 0, min_total = 0;

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return find_sets(par[a]);
    }

    ll get_comp(int u)
    {
        if(is_tree[u] == 0) return sum[u];
        return sum[u] - minval[u];  
    }

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) {
            snapshot.push_back({a,b,minval[a],is_tree[a],sum[a],sum_total});
            if(is_tree[a] == 1) {
                sum_total -= get_comp(a);
                is_tree[a] = 0;
                sum_total += get_comp(a);
            }
            return;
        }
        if(sz[a] < sz[b]) swap(a,b);
        snapshot.push_back({a,b,minval[a],is_tree[a],sum[a],sum_total});

        sum_total -= get_comp(a);
        sum_total -= get_comp(b);

        par[b] = a;
        sz[a] += sz[b];
        minval[a] = min(minval[a],minval[b]);
        sum[a] += sum[b];

        is_tree[a] &= is_tree[b];
        sum_total += get_comp(a);
    }   

    void rollback()
    {
        Sn c = snapshot.back();
        snapshot.pop_back();
        int u = c.u, v = c.v, min_val = c.min_val, state = c.is_tree;
        ll sumA = c.sumA;

        if(u != v) {
            sz[u] -= sz[v];
            par[v] = v;
        }
        
        sum[u] = sumA;
        is_tree[u] = state;
        minval[u] = min_val;
        sum_total = c.sum_a;
        return;
    }
} g;

vector<int> st[MM * 4];
map<int,int> mp;
ll ans[MM];

void update(int id,int l,int r,int u,int v,int pos)
{
    if(l > v || r < u) return;
    if(u <= l && r <= v) {
        st[id].push_back(pos);
        return;
    }
    int mid = (l + r) / 2;
    update(id*2,l,mid,u,v,pos);
    update(id*2+1,mid+1,r,u,v,pos);
}

void get(int id,int l,int r)
{
    int sz = g.snapshot.size();
    for(auto pos:st[id]) {
        int a = A[pos], b = B[pos];
        g.Unite(a,b);
    }

    if(l == r) {
        ans[l] = g.sum_total;

        while(g.snapshot.size() > sz) {
            g.rollback();
        }

        return;
    }

    int mid = (l + r) / 2;
    get(id*2,l,mid);
    get(id*2+1,mid+1,r);

    while(g.snapshot.size() > sz) {
        g.rollback();
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
    cin >> n >> k >> q;
    for(int i = 1;i <= n;i++) cin >> c[i];
    for(int i = 1;i <= k;i++) {
        cin >> A[i] >> B[i];
        mp[i] = 0;
    }

    for(int i = 1;i <= n;i++) {
        g.par[i] = i;
        g.sz[i] = 1;
        g.minval[i] = c[i];
        g.sum[i] = c[i];
        g.is_tree[i] = 1;
    }

    for(int i = 1;i <= q;i++) {
        int type,p; cin >> type >> p;
        if(type == 1) {
            update(1,1,q,mp[p],i - 1,p);
            mp.erase(p);
        }
        else mp[p] = i;
    }

    for(auto qr:mp) {
        update(1,1,q,qr.se,q,qr.fi);
    }

    get(1,1,q);

    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';
    return 0;
}