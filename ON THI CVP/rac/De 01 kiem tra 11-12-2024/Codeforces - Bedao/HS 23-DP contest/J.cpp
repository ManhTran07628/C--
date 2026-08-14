#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll dp[101][100001],w[N],v[N];

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
        cin >> w[i] >> v[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= s;j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]] + v[i]);
        }
    }
    cout << dp[n][s];
    return 0;
}