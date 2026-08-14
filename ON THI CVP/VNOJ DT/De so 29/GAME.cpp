#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "GAME"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    dp[2] = a[1]+a[2];
    for(int i = 3;i <= n;i++) {
        dp[i] = max({dp[i-1],dp[i-1] + a[i] - a[i-1],dp[i-3] + a[i-1] + a[i]});
    }
    cout << dp[n];
    return 0;
}