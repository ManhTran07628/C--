#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
ll a[MAXN],b[MAXN],c[MAXN];
ll dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1] = a[1];
    dp[2] = min(a[1]+a[2],b[1]);
    dp[3] = min({dp[2]+a[3],dp[1]+b[2],c[1]});
    for(int i = 4;i <= n;i++) {
        dp[i] = min({dp[i-1]+a[i],dp[i-2]+b[i-1],dp[i-3]+c[i-2]});
    }
    cout << dp[n];
    return 0;
}