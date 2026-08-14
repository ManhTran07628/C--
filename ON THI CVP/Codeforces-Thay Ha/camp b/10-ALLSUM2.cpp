#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll dp[N],p[N];
ll MOD = 1e9 + 7;

ll binpow(ll a,ll b)
{
    ll ans = 1;
    while(b > 0) {
        if(b % 2 == 1) ans = ans * a % MOD;
        b /= 2;
        a = a * a % MOD;
    }
    return ans;
}
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
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    p[0] = a[0];
    dp[0] = a[0];
    for(int i = 1;i < n;i++) {
        p[i] = ((a[i]*binpow(2,i-1)) + p[i-1]) % MOD;
        dp[i] = dp[i-1] + p[i];
    }
    cout << dp[n-1];
    return 0;
}