#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    dp[1] = 1; cout << 1 << ' ';
    for(int i = 2;i <= n;i++) {
        dp[i] = 1;
        if(s[i] == s[i-1]) dp[i] = max(dp[i],dp[i-1]);
        else dp[i] = max(dp[i],dp[i-2] + 2);

        if(i >= 3) {
            if(s[i] != s[i-1] && s[i-1] != s[i-2] && s[i-2] != s[i-1]) 
                dp[i] = max(dp[i],dp[i-3] + 3);
            // else if(s[i] == s[i-1] && s[i-1] != s[i-2] && s[i] != s[i-2]) 
            //     dp[i] = max({dp[i],dp[i-2] + 2,dp[i]})

        }
        cout << dp[i] << ' ';
    }
    cout << dp[n];
    return 0;
}

// ll rand(ll l,ll r)
// {
//     ll res = 0;
//     for(int i = 0;i < 4;i++)
//         res = (1ll * rand() << 15) ^ (res & ( (1 << 15) - 1)  );
//     return res % (r - l + 1) + l;
// }