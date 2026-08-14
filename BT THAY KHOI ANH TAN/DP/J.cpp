#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e4+7;
const int Ns = 3e6;
int prime[Ns],a[MAXN],dp[MAXN];

void sieve()
{
    fill(prime+1,prime+Ns+1,1);
    prime[0] = prime[1] = 0;
    for(int i = 2;i*i < Ns;i++)
        if(prime[i])
            for(int j = i*i;j < Ns;j+=i)
                prime[j] = 0;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)  cin >> a[i];
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++) {
            if(prime[a[i]+a[j]]) dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}