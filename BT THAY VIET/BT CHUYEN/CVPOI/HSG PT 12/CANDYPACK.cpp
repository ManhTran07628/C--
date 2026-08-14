#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5;
const int lim = 1e5;
int a[MM],dp[MM + 5],f[MM + 5];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= k;i++) cin >> a[i];


    f[0] = 1;
    for(int i = 1;i <= k;i++) {
        for(int j = a[i];j <= lim;j++) {
            f[j] |= f[j - a[i]];
        }
    }
    for(int i = 1;i <= k;i++) {
        for(int j = a[i];j <= lim;j++) {
            if(f[j]) {
                dp[j] = max(dp[j],dp[j - a[i]] + 1);
            }
        }
    }

    // for(int i = 1;i <= 7;i++)
    //     cout << dp[i] << ' ';
    cout << (f[n] ? dp[n] : -1);
    return 0;
}