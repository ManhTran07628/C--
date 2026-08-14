#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
const int MS = 1e6;
int n,m,q,k;
int a[MM][MM],res[MS];
vector<pii> adj[MS];

bool cmp(pii x,pii y)
{
    if(x.fi != y.fi) return x.fi < y.fi;
    return x.se < y.se;
}

void find_LIS(int mod)
{
    vector<int> v;
    for(auto x:adj[mod]) {
        int pos = upper_bound(v.begin(),v.end(),x.se) - v.begin();
        if(pos == v.size()) v.push_back(x.se);
        else v[pos] = x.se;
    }
    res[mod] = v.size();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q >> k;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            a[i][j] %= k;
            adj[ a[i][j] ].push_back({i,j});
        }
    
    for(int i = 0;i < k;i++) {
        sort(adj[i].begin(),adj[i].end(),cmp);
    }

    for(int i = 0;i < k;i++) {
        if(adj[i].size() == 0) continue;
        find_LIS(i);
    }

    // for(auto x:adj[1]) cout << x.fi << ' ' << x.se << '\n';

    while(q--) {
        int x; cin >> x;
        cout << res[x] << '\n';
    }

    return 0;
}