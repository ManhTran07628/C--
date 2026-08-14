#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN],ps[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    for(int i = 1;i <= n;i++) {
        if(i < k) dp[i] = dp[i-1] + a[i];
        cout << dp[i] << ' ';
    }
    // cout << dp[n];
    return 0;
}