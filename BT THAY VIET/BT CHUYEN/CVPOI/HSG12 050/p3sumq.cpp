#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 5e3 + 7;
int n,q,a[MM];


namespace subtask12
{
    int dp[MM][MM],cnt[MM][MM];
    void solve()
    {
        for(int k = 3;k <= n;k++) {
            for(int i = k - 2;i >= 1;i--) {

                for(int j = i + 1;j < k;j++) {
                    if(a[i] + a[j] + a[k] == 0) 
                        dp[i][k]++;
                }

                dp[i][k] += dp[i + 1][k] + dp[i][k - 1] - dp[i + 1][k - 1];

            }
        }


        while(q--) {
            int l,r; cin >> l >> r;
            cout << dp[l][r] << '\n';
        }
    }
}


const int MS = 2e6 + 7;
const int sz = 3e6;
namespace subtask3
{
    // a[i] + a[j] + a[k] = 0
    // a[i] + a[j] = X
    // a[k] = -X
    int dp[MM][MM],ps[MS],mp[MS];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int k = i + 1;k <= n;k++) {
                dp[i][k] = mp[sz + -(a[i] + a[k])];
                mp[sz + a[k]]++;
            }

            for(int k = i + 1;k <= n;k++) {
                mp[sz + a[k]]--;
            }
        }

        for(int k = 3;k <= n;k++) {
            for(int i = k - 2;i >= 1;i--) {
                dp[i][k] += dp[i + 1][k] + dp[i][k - 1] - dp[i + 1][k - 1];
            }
        }

        while(q--) {
            int l,r; cin >> l >> r;
            cout << dp[l][r] << '\n';
        }

    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> a[i];
    subtask3::solve();
    return 0;
}