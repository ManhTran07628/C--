#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll dp[MAXN];
ll M = 1e9+7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3;i < MAXN;i++) dp[i] = (dp[i-1]%M+dp[i-2]%M)%M;
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}