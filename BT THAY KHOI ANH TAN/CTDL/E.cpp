#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e5+7;
int n,num[MM],en[MM],m = 0,a[MM],q;
vector<int> adj[MM];

void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
}

void dfs(int u,int par)
{
    num[u] = ++m;
    for(auto v:adj[u]) {
        if(v == par) continue;
        dfs(v,u);
    }
    en[u] = m;
}

ll st[MM*4],lazy[MM*4];
void fix(int id,int l,int r)
{
    if(!lazy[id]) return;
    st[id] = lazy[id] * (r-l+1);
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
    int mid = (l+r)/2;
    update(id*2,l,mid,u,v,val);
    update(id*2+1,mid+1,r,u,v,val);
    st[id] = st[id*2] + st[id*2+1];
}

ll get(int id,int l,int r,int u,int v)
{
    fix(id,l,r);
    if(l > v || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = (l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

bool isprime(ll k)
{
    if(k < 2) return 0;
    for(ll i = 2;i*i <= k;i++)
        if(k % i == 0) return 0;
    return 1;
}

bool check(ll k)
{
    if(k <= 2) return 0;
    if(k % 2 == 0) return 1;
    return isprime(k-2);
}

void solve()
{
    dfs(1,0);
    for(int i = 1;i <= n;i++) {
        update(1,1,n,num[i],num[i],a[i]);
    }
    while(q--) {
        int t,u,v;
        cin >> t >> u;
        if(t == 1) {
            cin >> v;
            update(1,1,n,num[u],en[u],v);
        }
        else {
            ll sum = get(1,1,n,num[u],en[u]);
            cout << (!check(sum) ? "NO" : "YES") << '\n';
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}