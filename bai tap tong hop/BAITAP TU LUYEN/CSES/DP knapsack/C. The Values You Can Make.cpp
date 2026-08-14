#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int c[501],dp[501];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];    
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = k;j >= c[i];j--) {
            if(dp[j-c[i]]) dp[j] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0;i <= k;i++)  if(dp[i]) cnt++;
    cout << cnt << '\n';
    for(int i = 0;i <= k;i++)  if(dp[i]) cout << i << ' ';
    return 0;
}