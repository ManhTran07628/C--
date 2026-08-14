#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 1e5 + 7;
int n,x,y;

struct dl{
    ll a;
    ll s[10];
} a[MM];

ll dp[1 << 7],ndp[1 << 7];

bool cmp(dl &X,dl &Y)
{
    return X.a > Y.a;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    for(int i = 0;i < n;i++) cin >> a[i].a;
    

    for(int i = 0;i < n;i++) 
        for(int j = 0;j < x;j++)
            cin >> a[i].s[j];
            
    sort(a,a+n,cmp);

    for(int mask = 0;mask < (1 << x);mask++) dp[mask] = -oo;
    dp[0] = 0;

    for(int i = 0;i < n;i++) {
        for(int mask = 0;mask < (1 << x);mask++) ndp[mask] = -oo;

        for(int mask = 0;mask < (1 << x);mask++) {
            if(dp[mask] == -oo) continue;

            for(int j = 0;j < x;j++)
                if(!(mask >> j & 1))
                    ndp[mask | (1 << j)] = max(ndp[mask | (1 << j)],dp[mask] + a[i].s[j]);
            
            int r = __builtin_popcount(mask);

            if(i < r + y) ndp[mask] = max(ndp[mask],dp[mask] + a[i].a);
            else ndp[mask] = max(ndp[mask],dp[mask]);
        }

        for(int mask = 0;mask < (1 << x);mask++) dp[mask] = ndp[mask];
                
    }
    cout << dp[(1 << x) - 1];
    return 0;
}
