#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll c[10001];
ll dp[10001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < n;i++) {
        cin >> c[i];
        dp[i] = 1e18;
    }
    for(int i = 0;i < n;i++) {
        for(int j = max(0,j-k);j <= min(n,j+k);j++) {
            if(j-k-1 >= 0) dp[i] = min(dp[i],dp[j-k-1]+c[i]);
        }
    }
    ll ans = 1e18;
    for(int i = 0;i < n;i++) {
        ans = min(ans,dp[i]);
    }
    cout << ans;
    return 0;
}