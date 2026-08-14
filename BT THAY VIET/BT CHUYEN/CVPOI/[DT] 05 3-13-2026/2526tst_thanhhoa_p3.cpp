#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e3 + 7;
ll T,n,h[MM];
pair<ll,ll> a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> T;
    while(T--) {
        cin >> n;
        for(int i = 1;i <= n;i++) {
            cin >> a[i].fi;
            a[i].se = i;
        }
        sort(a+1,a+n+1);
        ll L = 1;
        for(int i = 1;i <= n;i++) {
            h[i] = 1;
            for(int j = 1;j < i;j++)
                if(a[i].fi % a[j].fi == 0) 
                    h[i] = max(h[i],h[j] + 1);
            L = max(L,h[i]);
        }
        // cout << L << '\n';

        ll k = L / 2;
        vector<ll> v;
        for(int i = 1;i <= n;i++) 
            if(h[i] <= k)
                v.push_back(a[i].se);
        cout << v.size() << ' ';
        for(auto x:v) cout << x << ' '; cout << '\n';
    }
    return 0;
}