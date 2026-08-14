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
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) dp[i] = 1e9;
    for(int i = 1;i <= n;i++) {
        for(int j = a[i];j <= m;j++) {
            dp[j] = min(dp[j],dp[j-a[i]]+1);
        }
    }
    cout << dp[m];
    return 0;
}