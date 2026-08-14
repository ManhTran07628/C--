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
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    dp[1] = 0;
    dp[2] = abs(a[1]-a[2]);
    for(int i = 2;i <= n;i++) {
        dp[i] = 1e9;
        for(int j = 1;j <= k;j++) {
            if(i - j >= 1) {
                dp[i] = min(dp[i],dp[i-j] + abs(a[i]-a[j]));
            }
        }
        cout << dp[i] << " ";
    }
    //cout << dp[n];
    return 0;
}