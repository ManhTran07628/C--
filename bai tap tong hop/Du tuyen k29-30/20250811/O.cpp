#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e4+7;
ll dp[MM],a[MM];
int n,k;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "teamwork"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        ll max_v = 0;
        for(int j = i;j >= max(1,i-k+1);j--) {
            max_v = max(max_v,a[j]);
            dp[i] = max(dp[i],dp[j-1]+max_v*(i-j+1));
        }
    }
    cout << dp[n];
    return 0;
}