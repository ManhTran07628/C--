#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll h[MAXN],dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[2]-h[1]);
    dp[3] = min(dp[2]+abs(h[3]-h[2]),abs(h[3]-h[1]));
    // cout << dp[2] << ' ' << dp[3];
    for(int i = 4;i <= n;i++) {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),abs(h[i]-h[i-2])+dp[i-2]);
    }
    cout << dp[n];
    return 0;
}