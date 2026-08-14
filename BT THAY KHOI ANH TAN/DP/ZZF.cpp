#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],dpL[MAXN],dpR[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    
    for(int i = 1,j = 1;i <= n;i++) {
        while(a[i]+k >= a[j] && j <= n) {
            dpL[j] = max(dpL[j-1],j-i+1);
            j++;
        }
    }
    for(int i = n,j = n;i >= 1;i--) {
        while(a[i]-k <= a[j] && j >= 1) {
            dpR[j] = max(dpR[j+1],i-j+1);
            j--;  
        }
    }
    // for(int i = 1;i <= n;i++) {
    //     cout << dpR[i] << ' ';
    // }
    // cout << '\n';
    int ans = 0;
    for(int i = 0;i <= n;i++) {
        ans = max(ans,dpL[i]+dpR[i+1]);
    }
    cout << ans;
    return 0;
}