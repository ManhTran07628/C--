#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN],c[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,x;
    cin >> n >> x;
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
    fill(dp+1,dp+x+1,1e9);
    for(int i = 1;i <= n;i++) {
        for(int s = c[i];s <= x;s++) {
            dp[s] = min(dp[s],dp[s-c[i]]+1);
        }
    }
    cout << (dp[x] != (int)1e9 ? dp[x] : -1);
    return 0;
}