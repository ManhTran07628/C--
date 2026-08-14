#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n,h[MM + 7];

struct DSU
{
    vector<int> par,val;
    DSU(int n) : par(n + 3), val(n + 3) {
        for(int i = 1;i <= n;i++) {
            par[i] = i;
            val[i] = h[i];
        }
    };

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
        if(b > a) swap(a,b);
        par[b] = a;
        val[a] = max(val[a],val[b]);
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bool ok = 1;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    for(int i = 2;i <= n;i++) {
        if(h[i] <= h[i-1]) ok = 0;
    }
    if(ok) {
        cout << 0;
        return 0;
    }
    DSU g(n);

    int cnt = 0;

    while(1) {
        vector<pii> v;
        for(int i = g.find_sets(1);i <= n;) {
            int x = g.find_sets(i);
            int y = g.find_sets(x + 1);
            if(x <= n && y <= n && g.val[y] <= g.val[x] && x != y) v.push_back({x,y});
            i = g.find_sets(i) + 1;
        }

        if(v.empty()) break;
        for(auto i:v) {
            g.Unite(i.fi,i.se);
        } 
        cnt++; 
    }
    cout << cnt;
    return 0;
}
