#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6 + 7;
int t,n,en[MM],m,par[MM];
vector<int> adj[MM];

void solve()
{
    cin >> n;
    for(int i = 2;i <= n;i++) {
        int p; cin >> p;
        par[i] = p;
    }
    cin >> m;
    int mi = 1e9;
    vector<int> vec;
    for(int i = 1;i <= m;i++) {
        cin >> en[i];
        mi = min(mi,en[i]);
    }

    for(int i = 1;i <= m;i++) {
        if(mi != en[i]) vec.push_back(en[i]);
    }

    cout << vec.size() << ' ';
    for(auto e:vec) cout << e << ' ';
    cout << '\n';

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
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}