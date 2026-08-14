#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e6;
set<ll> ans;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n; cin >> n;
    for(ll x = 1;x * x <= n;x++) {
        for(ll y = x+1;x * x + y * y <= n;y++) {
            ans.insert(x * x + y * y);
        }
    }
    if(ans.size() == 0) cout << 0;
    else {
        cout << ans.size() << '\n';
        for(auto x:ans) cout << x << ' ';
    }
    return 0;
}
