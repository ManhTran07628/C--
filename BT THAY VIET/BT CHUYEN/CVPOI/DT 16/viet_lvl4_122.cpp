#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
const int LOG = 21;
int n,q;
int a[MM],comp[MM],up[MM][LOG + 1],h[MM];
vector<int> adj[MM];

int prime[MM],mp[MM],d[1001][5134];
vector<int> vec;

void sieve()
{
    fill(prime+1,prime+MM,1);
    for(ll i = 2;i * i < MM;i++)
        if(prime[i])
            for(ll j = i * i;j < MM;j += i)
                prime[j] = 0;

    for(ll i = 2;i < MM;i++)
        if(mp[i] == 0)
            for(ll j = i;j < MM;j += i)
                if(mp[j] == 0)
                    mp[j] = i;

    for(int i = 2;i < MM;i++)
        if(mp[i] == 0) mp[i] = i;
}

void dfs(int u,int par)
{
    vector<int> factor;
    int f = a[u];
    while(f > 1) {
        int p = mp[f];
        factor.push_back(p);
        d[u][ comp[p] ]++;
        while(f % p == 0) f /= p;
    }
    
    for(int i = 1;i <= vec.size();i++) 
        d[u][i] += d[par][i];



    for(auto v:adj[u]) {
        if(v == par) continue;
        h[v] = h[u] + 1;
        up[v][0] = u;
        dfs(v,u);
    }
}

void process()
{
    dfs(1,0);
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
    sieve();
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i < n;i++) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1;i <= n;i++) {
        int d = a[i];
        while(d > 1) {
            int p = mp[d];
            vec.push_back(p);
            while(d % p == 0) d /= p;
        }
    }

    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    for(int i = 0;i < vec.size();i++) {
        comp[ vec[i] ] = i + 1;
    }

    dfs(1,0);

    // for(int i = 1;i <= n;i++) 
        // for(int j = 1;j <= vec.size();j++) cout << i << ' ' << vec[j - 1] << ' ' << d[i][j] << '\n';

    while(q--) {
        int u,v; cin >> u >> v;
        int res = 0;
        for(int i = 1;i <= vec.size();i++) {
            int cnt = d[u][i] + d[v][i] - d[LCK(u,v)][i];
            // cout << cnt << ' ' << vec[i - 1] << '\n';
            res += cnt > 0;
        }
        cout << res << '\n';
    }
    return 0;
}