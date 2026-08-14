#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],dp[N];
ll MOD = 1e9+7;
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
    ll n,s;
    cin >> n >> s;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = a[i];j <= s;j++) {
            dp[j] = (dp[j] + dp[j-a[i]]) % MOD;
        }
    }
    cout << dp[s];
    return 0;
}