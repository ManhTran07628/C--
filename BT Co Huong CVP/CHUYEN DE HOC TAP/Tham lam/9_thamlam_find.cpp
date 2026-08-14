#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll)2e9
const int MM = 1e5+7;
int n;
pair<int,int> C[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> C[i].fi >> C[i].se;
    }
    sort(C+1,C+n+1);
    ll ans = 0,c_id = 1;
    C[n+1] = {oo,oo};
    for(int i = 2;i <= n+1;i++) {

        if(C[i].fi > C[i-1].se) {
            ll dist = C[i-1].se - C[c_id].fi;
            ans = max(ans,dist);
            c_id = i;
        }
        
    }
    cout << ans;
    return 0;
}