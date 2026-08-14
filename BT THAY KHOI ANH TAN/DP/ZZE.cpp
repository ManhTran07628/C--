#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],a[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        dp[i] = 1e18;
    }
    for(int i = 1;i <= n;i++) {
        dp[i] = min(dp[i],dp[i-1]+a[i]);
        if(i >= 10) {
            int val = 1e18,sum = 0;
            for(int j = i-9;j <= i;j++) {
                val = min(val,a[j]);
                sum += a[j];
            }
            dp[i] = min(dp[i],dp[i-10]+(sum-val));
        }
    }
    cout << dp[n];
    return 0;
}