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
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
        dp[i] = 1e18;
    }
    dp[1] = 0;
    dp[2] = abs(h[1]-h[2]);
    for(int i = 3;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i-j >= 1) dp[i] = min(dp[i-j]+abs(h[i]-h[i-j]),dp[i]);
        }
    }
    cout << dp[n];
    return 0;
}