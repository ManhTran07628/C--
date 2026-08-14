#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
int a[MAXN],dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    // dp[i] la so dong xu it nhat can phai dung de tra so tien i
    fill(dp,dp+MAXN,1e9);
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(j-a[i] >= 0) dp[j] = min(dp[j-a[i]]+1,dp[j]);
        }
    }
    if(dp[k] == int(1e9)) cout << -1;
    else cout << dp[k];
    return 0;
}