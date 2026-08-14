#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
int n,lastpos[MM];
vector<int> adj[MM];

struct DSU
{
    int par[MM] = {}, sz[MM] = {};
    void build(int n)
    {
        for(int i = 1;i <= n;i++) {
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    bool Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return 0;
        if(sz[a] < sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
        return 1;
    }
} g;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    g.build(n);
    ll mst = 0;
    for(int i = 1;i <= n;i++) {
        int x; cin >> x;
        if(lastpos[x] == 0) {
            lastpos[x] = i;
        }
        else {
            if(!g.Unite(lastpos[x],i)) continue;
            mst += x;
        }   
    }
    for(ll i = MM - 1;i >= 1;i--) {
        
        int prev_pos = 0;
        for(ll j = i;j < MM;j += i) {
            if(!lastpos[j]) continue;
            if(prev_pos != 0) {
                if(g.Unite(prev_pos,lastpos[j])) mst += i;
            }
            prev_pos = lastpos[j];
        }
    }
    cout << mst;
    // cout << mst << ' ' << max_sz;

    
    return 0;
}