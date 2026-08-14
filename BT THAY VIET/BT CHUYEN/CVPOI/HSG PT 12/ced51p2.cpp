#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e6;


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll l,r; cin >> l >> r;
    vector<pii> ans;
    for(ll i = l;i <= r;i+=2) {
        ans.push_back({i,i+1});
    }
    if(ans.size() != (r - l + 1) / 2) cout << "NO";
    else {
        cout << "YES" << '\n';
        for(auto x:ans) cout << x.fi << ' ' << x.se << '\n';
    }
    return 0;
}