#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],ps[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int max_val = 0,ans = 1e18;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ps[i] = ps[i-1] + a[i];
    }
    for(int i = k;i <= n;i++) {
        max_val = max(max_val,ps[i-k]);
        ans = min(ans,ps[i]-max_val);
    }
    cout << ans;
    return 0;
}