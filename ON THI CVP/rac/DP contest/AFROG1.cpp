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
    #define taskname ""
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
    dp[1] = 0;
    dp[2] = abs(a[2]-a[1]);
    for(int i = 3;i <= n;i++) {
        dp[i] = min(dp[i-1] + abs(a[i]-a[i-1]),dp[i-2] + abs(a[i]-a[i-2]));
    }
    cout << dp[n];
    return 0;
}