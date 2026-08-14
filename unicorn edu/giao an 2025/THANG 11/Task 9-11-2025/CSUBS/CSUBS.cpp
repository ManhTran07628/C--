#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6 + 7;
const int MOD = 1e6;
int t,a,s,b,cnt[MM];
ll dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "CSUBS"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> t >> a >> s >> b;
    for(int i = 1;i <= a;i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    dp[0] = 1;

    for(int i = 1;i <= t;i++)
        for(int sum = b;sum >= 1;sum--)

            for(int nums = 1;nums <= cnt[i];nums++) {
                if(sum >= nums)
                    dp[sum] = (dp[sum] + dp[sum - nums]) % MOD;
            }

    ll res = 0;
    for(int i = s;i <= b;i++) res = (res + dp[i]) % MOD;
    cout << res;
    return 0;
}
