#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
int n,a[250],dp[250][250],vis[250][250],ans = 0;


ll f(int l,int r)
{
    if(l == r) {
        ans = max(ans,a[l]);
        return a[l];
    }
    if(vis[l][r]) return dp[l][r];
    dp[l][r] = -1;
    vis[l][r] = 1;
    for(int k = l;k < r;k++) {
        int L = f(l,k);
        int R = f(k+1,r);
        if(L == R) dp[l][r] = max(dp[l][r],L+1);
    }
    ans = max(ans,dp[l][r]);
    return dp[l][r];
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "248"
    if(fopen(taskname ".in","r"))
    {
        freopen(taskname ".in","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    int d = f(1,n);
    cout << ans;
    return 0;
}