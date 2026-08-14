#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[501],dp[501];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        int mq = 0;
        for(int j = i;j >= max(1LL,i-k+1);j--) {
            mq = max(mq,a[j]);
            dp[i] = max(dp[i],dp[j-1]+mq*(i-j+1));
        }
    }
    cout << dp[n];
    return 0;
}