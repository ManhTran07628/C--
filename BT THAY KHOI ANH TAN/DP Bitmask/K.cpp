#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 17;
int dp[1 << 16][MM],f[MM][MM],n;
string g[MM],w[MM];

void readinput()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> g[i] >> w[i];
    }
}

void solve()
{
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            if(g[j] == g[i] || w[j] == w[i]) f[i][j] = f[j][i] = 1;
        }
    }

    for(int i = 0;i < n;i++) dp[1 << i][i] = 1;
    int ans = 0;
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int p_mask = mask ^ (1 << i);
                for(int j = 0;j < n;j++) {
                    if(p_mask >> j & 1) {
                        if(f[i+1][j+1])
                            dp[mask][i] |= dp[p_mask][j];
                    }
                }
            }
            if(dp[mask][i]) ans = max(ans,__builtin_popcount(mask));
        }

    }

    cout << n-ans;
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}   