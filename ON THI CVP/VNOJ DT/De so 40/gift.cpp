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
    #define taskname "gift"
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
    ll max1 = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[i] - a[j] >= k) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        max1 = max(max1,dp[i]);
    }
    cout << max1;
    return 0;
}