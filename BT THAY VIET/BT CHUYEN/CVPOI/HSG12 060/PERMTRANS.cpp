#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
int n,m,q,P[MM][MM];

struct DSU
{
    int par[MM] = {};

    int find_sets(int a)
    {
        if(a == par[a]) return a;
        return par[a] = find_sets(par[a]);
    }

    void Unite(int a,int b)
    {
        a = find_sets(a);
        b = find_sets(b);
        if(a == b) return;
        par[b] = a;
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
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) g.par[i] = i;
    
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> P[i][j];
            g.Unite(j,P[i][j]);
        }
    }

    while(q--) {
        int a,b; cin >> a >> b;
        if(g.find_sets(a) == g.find_sets(b)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }


    return 0;
}