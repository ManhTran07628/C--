#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int ans = 0;
    dp[1] = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++) 
            if(a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1);
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}