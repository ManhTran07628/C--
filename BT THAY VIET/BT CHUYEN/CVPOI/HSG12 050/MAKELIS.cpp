#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 50 + 7;
int dp[MM][MM][MM][MM];
int n,a[MM];

int f(int L,int R,int low,int high)
{
    if(L > R) return 0;
    if(low > high) return 0;
    if(dp[L][R][low][high] != -1) return dp[L][R][low][high];

    int cur_res = max(f(L+1,R,low,high),f(L,R-1,low,high));

    if(low <= a[L] && a[L] <= high) 
        cur_res = max(cur_res,f(L+1,R,a[L],high) + 1);

    if(low <= a[R] && a[R] <= high) 
        cur_res = max(cur_res,f(L,R-1,low,a[R]) + 1);

    if(low <= a[R] && a[R] <= high)
        cur_res = max(cur_res,f(L+1,R-1,a[R],high) + 1);
    
    if(low <= a[L] && a[L] <= high)
        cur_res = max(cur_res,f(L+1,R-1,low,a[L]) + 1);

    if(low <= a[R] && a[L] <= high && a[R] <= a[L])
        cur_res = max(cur_res,f(L+1,R-1,a[R],a[L]) + 2);

    dp[L][R][low][high] = cur_res;
    return cur_res;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << f(1,n,1,50);
    return 0;
}