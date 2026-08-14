#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 3005;
int dp[MAXN];
pair<int,int> ball[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> ball[i].fi >> ball[i].se;
    }
    sort(ball+1,ball+n+1,greater<pair<int,int>>());
    fill(dp+1,dp+n+1,1e15);
    dp[1] = ball[1].se;
    for(int i = 2;i <= n;i++) {
        int cost = 0;
        dp[i] = min(dp[i-1]+ball[i].se,dp[i]);
        for(int j = i-1;j >= 1;j--) {
            cost += abs(ball[j].fi-ball[i].fi);
            dp[i] = min(dp[i],dp[j-1]+cost+ball[i].se);
        }
    }
    cout << dp[n];
    return 0;
}