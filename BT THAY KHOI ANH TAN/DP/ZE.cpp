#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,s = 0;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        s += a[i];
    }
    dp[0] = 1;
    int ans = s;
    for(int i = 1;i <= n;i++) {
        for(int j = s/2;j >= a[i];j--) {
            if(dp[j-a[i]]) {
                dp[j] = 1;
            }
        }
    }
    for(int l = 1;l <= s/2;l++) {
        if(dp[l]) {
            int r = s-l;
            ans = max(ans,l*r);
        }
    }
    cout << ans;
    return 0;
}