#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e4+7;
int a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll cur_val = a[i];
        for(int j = i;j <= n;j++) {
            cur_val = min(cur_val,a[j] * 1ll);
            ans = max(ans,cur_val * (j-i+1));
        }
    }
    cout << ans;
    return 0;
}