#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e6 + 7;
int n,x[MM],dp1[1 << 20],cnt[MM],dp2[1 << 20],dp3[1 << 20];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
        cnt[ x[i] ]++;
    }
    int sz = 20;
    for(int i = 0;i < (1 << sz);i++) {
        dp1[i] = dp2[i] = dp3[i] = cnt[i];
    }
    for(int i = 0;i < sz;i++)
        for(int mask = 0;mask < (1 << sz);mask++) {
            if(mask >> i & 1) {
                dp1[mask] += dp1[mask ^ (1 << i)];
                dp2[mask ^ (1 << i)] += dp2[mask];
            }
        }

    // cout << dp3[4];
    for(int i = 1;i <= n;i++) {
        ll t = x[i] ^ ((1 << sz) - 1);
        cout << dp1[ x[i] ] << ' ' << dp2[ x[i] ] << ' ' << n - dp1[t] << '\n';
    }
    return 0;
}