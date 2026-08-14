#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dp1[MAXN],dp2[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        dp1[i] = 1;
        for(int j = 1;j < i;j++) 
        if(a[j] < a[i]) dp1[i] = max(dp1[i],dp1[j]+1);
    }
    for(int i = n;i >= 1;i--) {
        dp2[i] = 1;
        for(int j = n;j > i;j--)
        if(a[j] < a[i]) dp2[i] = max(dp2[i],dp2[j]+1);
    }
    int ans = 1;
    for(int i = 1;i <= n;i++) {
        int d = min(dp1[i],dp2[i]);
        ans = max(ans,d*2-1);
    }
    cout << ans;
    return 0;
}