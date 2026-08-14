#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e5+7;
int n,x,h[MM],s[MM],dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(int i = 1;i <= n;i++) cin >> h[i];
    for(int i = 1;i <= n;i++) cin >> s[i];

    for(int i = 1;i <= n;i++) {
        for(int j = x;j >= h[i];j--) {
            dp[j] = max(dp[j],dp[j-h[i]]+s[i]);
        }
    }
    cout << dp[x];
    return 0;
}