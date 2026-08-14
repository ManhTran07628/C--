#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],a[MAXN];

bool check(int k)
{
    int q = sqrt(k);
    if(q*q == k && k > 0) return 1;
    return 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;
        for(int j = i;j >= max(1LL,i-10);j--) {
            int d = abs(a[j]-a[i]);
            if(check(d)) dp[i] = max(dp[j]+1,dp[i]);
        }
        ans = max(dp[i],ans);
    }
    cout << ans;
    return 0;
}