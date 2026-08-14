#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1e5 + 7;
int n,k,a[MM],suffix[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1);
    for(int i = n;i >= 1;i--) {
        int r = upper_bound(a+r,a+n+1,a[i] + k) - a - 1;
        suffix[i] = max(suffix[i+1],r - i + 1);
    }
    int res = 0;
    for(int i = 1,j = 1;i <= n;i++) {
        while(j <= n && a[j] - a[i] <= k) j++;
        res = max(res,j - i + suffix[j]);
    }
    cout << res;
    return 0;
}