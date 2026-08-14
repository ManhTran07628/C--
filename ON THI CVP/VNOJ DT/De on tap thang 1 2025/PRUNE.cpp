#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[N],dp[N],b[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PRUNE"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    int n,k;
    cin >> n >> k;
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= k;i++) {
        dp[i] = 1;
        for(int j = 1;j < i;j++) {
            if(a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1);
        }
    }
    b[k] = 1;
    for(int i = k+1;i <= n;i++) {
        dp[i] = 1;
        bool kt = 0;
        for(int j = k;j < i;j++) {
            if(a[i] > a[j] && b[j]) {
                if(j == k) {
                    kt = 1;
                }
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        if(!kt) {
            dp[i] = 0;
        }
        else b[i] = 1;
    }
    for(int i = 1;i <= n;i++) ans = max(ans,dp[i]);
    cout << ans;
    return 0;
}