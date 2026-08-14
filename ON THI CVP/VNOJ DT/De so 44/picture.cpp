#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],dp[500][500];
ll n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "picture"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    dp[1][1] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= k;j++) {
            for(int x = 1;x < i;x++) {
                dp[i][j] = dp[i][j] + dp[i-x][j];
            }
        }
    }
    ll ans = 0;
    for(int i = 2;i <= n;i++) {
        ans += dp[i][1];
    }
    cout << ans;
    return 0;
}
