#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 2e5;
int n,q;
ll w[MM + 5];

multiset<ll> ms; 
void solve()
{
    for(int i = 1;i <= n;i++) {
        if(ms.empty()) {
            ms.insert(w[i]);
            continue;
        }
        auto bag = ms.upper_bound(q - w[i]);
        if(bag == ms.begin()) {
            ms.insert(w[i]);
            continue;
        } 
        ll val = *prev(bag); 
        if(val + w[i] <= q) {
            ms.erase(prev(bag));
            ms.insert(val + w[i]);
        }
        else ms.insert(w[i]);
    }
    // for(auto x:ms) cout << x << ' ';
    cout << ms.size() << '\n';
    ms.clear();
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i = 1;i <= n;i++) cin >> w[i];
        solve();
    }
    return 0;
}