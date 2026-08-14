#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll d[MAXN],dp[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,a,b,c;
    cin >> n >> a >> b >> c;
    for(int i = 1;i <= n;i++) {
        cin >> d[i];
    }
    for(int i = 1;i <= n;i++) {
        if(d[i] == 1) 
            dp[i] = min({a+dp[max(0,i-1)],b+dp[max(0,i-7)],c+dp[max(0,i-30)]});
        else dp[i] = min({a+dp[max(0,i-1)],b+dp[max(0,i-7)],c+dp[max(0,i-30)],dp[i-1]});
    }
    cout << dp[n];
    return 0;
}