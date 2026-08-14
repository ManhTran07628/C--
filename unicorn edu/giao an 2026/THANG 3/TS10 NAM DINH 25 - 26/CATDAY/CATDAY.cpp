#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e6 + 7;
map<ll,ll> mp;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "CATDAY"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k; cin >> n >> k;
    map<ll, ll, greater<ll>> mp;
    mp[n] = 1;
    while (k > 0) {
        auto it = mp.begin();
        ll length = it->first;
        ll count = it->second;
        if (k < count) {
            mp[length] = count - k;
            k = 0; 
        } 
        else {
            k -= count;
            ll s1 = length / 2;
            ll s2 = (length + 1) / 2; 
            mp[s1] += count;
            mp[s2] += count;
            mp.erase(it);
        }
    }
    cout << mp.begin()->first << " " << mp.begin()->second << endl;
    return 0;
}