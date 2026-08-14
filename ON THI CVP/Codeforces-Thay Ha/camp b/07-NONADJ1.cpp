#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll dp[100][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2;i <= n;i++) {
        dp[i][0] += dp[i-1][0];
        dp[i][0] += dp[i-1][1];
        dp[i][1] += dp[i-1][0];
    }
    cout << dp[n][0]+dp[n][1];
    return 0;
}