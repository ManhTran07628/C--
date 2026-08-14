#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 9 + 7;
int n,k;
ll dp[MM][100][1 << 10];
vector<int> valid;


bool check(int mask,int pmask)
{
    for(int i = 0;i < n;i++) {
        if(!(mask >> i & 1)) continue;

        // cout << i << ' ' << (mask >> i & 1) << ' ' << (pmask >> i & 1) << '\n';
        if(0 < i) if(pmask >> (i - 1) & 1) return 0;
        if(i < n - 1) if(pmask >> (i + 1) & 1) return 0;
        if(pmask >> i & 1) return 0;
    }
    return 1;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for(int mask = 0;mask < (1 << n);mask++) {
        if(mask & (mask >> 1)) continue;

        valid.push_back(mask);
    }

    for(int mask:valid) {
        int cur = __builtin_popcount(mask);
        if(cur <= k)
            dp[1][cur][mask] = 1;
    }

    for(int x = 2;x <= n;x++) {
        for(int mask:valid) {
            int cur = __builtin_popcount(mask);

            for(auto pmask: valid) {

                if(check(mask,pmask)) {


                    for(int i = cur;i <= k;i++) 
                        dp[x][i][mask] = (dp[x][i][mask] + dp[x-1][i - cur][pmask]);
                    


                }

            }

        }
    }

    ll ans = 0;
    for (int mask : valid) {
        ans += dp[n][k][mask];
    }
    cout << ans;
    return 0;
}