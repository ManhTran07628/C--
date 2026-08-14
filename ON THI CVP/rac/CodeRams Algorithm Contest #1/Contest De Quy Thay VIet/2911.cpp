#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll dp[N];
int MOD = 100003;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> n >> k;
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            if(i - j >= 0) {
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }
    cout << dp[n];
    return 0;
}