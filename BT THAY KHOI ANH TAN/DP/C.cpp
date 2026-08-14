#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll t[MAXN],r[MAXN],dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> t[i];
    for(int i = 1;i <= n-1;i++) cin >> r[i];
    dp[1] = t[1];
    dp[2] = min(t[1]+t[2],r[1]);
    for(int i = 3;i <= n;i++) {
        dp[i] = min(dp[i-1]+t[i],dp[i-2]+r[i-1]);
    }
    cout << dp[n];
    return 0;
}