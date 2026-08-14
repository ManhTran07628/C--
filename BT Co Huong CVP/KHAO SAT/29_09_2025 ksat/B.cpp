#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)1e18
const int MM = 1e6+7;
ll t,s;
vector<int> a;
map<ll,bool> pow3;

void prepare()
{
    for(ll i = 1;i < MM;i++) {
        ll p = i*i*i;
        if(p > oo) break; 
        pow3[p] = 1;
    }
}

void solve()
{
    cin >> s;
    a.clear();
    while(s > 0) {
        a.push_back(s % 10);
        s /= 10;
    }
    int n = a.size();
    reverse(a.begin(),a.end());
    ll ans = -1;
    for(int mask = 1;mask < (1 << n);mask++) {
        vector<ll> comp;

        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                comp.push_back(a[i]);
            }
        }

        ll nums = 0;
        for(auto i:comp) 
            nums = nums * 10 + i * 1ll;
        
        if(pow3[nums]) ans = max(ans,nums);

    }

    cout << ans << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prepare();
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}