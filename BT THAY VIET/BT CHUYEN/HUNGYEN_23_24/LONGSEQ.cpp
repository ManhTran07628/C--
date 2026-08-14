#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e6+7;
ll n,k,a[MM],ps[MM];
map<ll,pair<int,int>> mp;
void readInput()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    
}

namespace subtask1
{
    void solve()
    {
        for(int i = 0;i <= k;i++) {
            mp[1 << i] = {1,0};
        }
        int ans = 0;
        for(int i = 1;i <= n;i++) {
            ll s = 0;
            for(int j = i;j <= n;j++) {
                s += a[j];
                if(mp[s].fi) ans = max(ans,j-i+1);
            }
        }
        cout << ans << '\n';
    }
}

namespace subtask3
{
    void solve()
    {
        ll sum = 0;
        ll ans = 0;
        mp[0] = {1,0};
        for(ll i = 1;i <= n;i++) {
            ps[i] = ps[i-1] + a[i];
            for(ll j = 0;j <= k;j++) {
                ll psd = ps[i] - (1ll << j);
                if(mp[psd].fi) {
                    ll d = mp[psd].se;
                    ans = max(ans,i-d);
                }
            }
            if(!mp[ps[i]].fi) {
                mp[ps[i]].fi = 1;
                mp[ps[i]].se = i;
            }
        }
        cout << ans;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readInput();
    if(n <= 1000) subtask1::solve();
    else subtask3::solve();
    return 0;
}