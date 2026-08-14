#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,k;
ll x[MM];

void readinput()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> x[i];
}

string to_str(ll a)
{
    string s;
    while(a > 0) {
        char c = a % 10 + '0'; s += c;
        a /= 10;
    }
    reverse(s.begin(),s.end());
    return s;
}

ll bor(ll a,ll b)
{
    ll cnt = 0;
    string s1 = to_str(a), s2 = to_str(b);
    while(s1.size() != s2.size()) {
        if(s1.size() < s2.size()) s1 = '0' + s1;
        else if(s1.size() > s2.size()) s2 = '0' + s2;
    }
    ll res = 0;
    for(int i = 0;i < s1.size();i++) {
        ll c = (s1[i] - '0' + s2[i] - '0') % 10;
        res = res * 10 + c;
    }
    return res;
}

namespace solb
{
    ll ans = 0,l1 = 0,l2 = 0;
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(i == j) continue;
                ans = max(ans,bor(x[i],x[j]));
            }
        }
        cout << ans;
    }
}

namespace subtask1
{
    ll ans = 0;
    ll dp[MM][1 << 2];
    void solve()
    {
        sort(x+1,x+n+1);
        for(int i = 1;i <= n;i++) {
            for(int mask = 0;mask < (1 << k);mask++) {
                dp[i][mask] = dp[i-1][mask];
                for(int j = 0;j < k;j++) {
                    if(mask >> j & 1) {
                        int prev_mask = mask ^ (1 << j);
                        int nums = __builtin_popcount(mask);
                        if(nums == 1) dp[i][mask] = x[i];
                        else if(nums == 2) {
                            dp[i][mask] = max(dp[i][mask],bor(dp[i-1][prev_mask],x[i]));
                            ans = max(ans,dp[i][mask]);
                        }
                    }
                }
            }
        }
        cout << ans;
    }
}

namespace subtask3
{
    ll ans = 0;
    ll dp[MM][1 << 3];
    void solve()
    {
        sort(x+1,x+n+1);
        for(int i = 1;i <= n;i++) {
            for(int mask = 0;mask < (1 << k);mask++) {
                dp[i][mask] = dp[i-1][mask];
                for(int j = 0;j < k;j++) {
                    if(mask >> j & 1) {
                        int prev_mask = mask ^ (1 << j);
                        int nums = __builtin_popcount(mask);
                        if(nums == 1) dp[i][mask] = x[i];
                        else if(nums == 2) dp[i][mask] = bor(dp[i-1][prev_mask],x[i]);
                        else if(nums == 3) {
                            dp[i][mask] = max(dp[i][mask],bor(dp[i-1][prev_mask],x[i]));
                            ans = max(ans,dp[i][mask]);
                        }
                    }
                }
            }
        }
        cout << ans;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    if(n <= 7000 && k == 2) solb::solve();
    else if(n > 7000 && k == 2) subtask1::solve();
    else subtask3::solve();
    return 0;
}