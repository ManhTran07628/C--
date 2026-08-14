#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 10+7;
int n;
vector<int> adj[MM];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++) {
        int u;
        cin >> u;
        // adj[i].push_back(u);
        adj[u].push_back(i);
    }
    int ans = 0;
    for(int mask = 0;mask < (1 << n);mask++) {
        map<int,int> ds;
        bool ok = 1;
        for(int i = 0;i < n;i++) {
            if((mask >> i) & 1) {
                ds[i+1] = 1;
                if(i+1 == n) ok = 0;
            }
        }
        if(!ok) continue;
        for(auto i:ds) {
            for(auto v:adj[i.fi]) {
                if(!ds[v] && v != n) {
                    ok = 0;
                    break;
                }
            }
            if(!ok) break;
        }
        ans += ok;
    }
    cout << ans;
    return 0;
}