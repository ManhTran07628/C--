#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e3 + 7;
int n,m,p[MM],t[MM],o[MM];
ll dp[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        cin >> p[i] >> t[i] >> o[i];
    
    for(int i = 1;i <= n;i++) {
        for(int j = t[i];j <= m;j++) {
            dp[j] = max(dp[j],dp[j - t[i]] + o[i]);
        }
    }
    cout << dp[m];
    return 0;
}