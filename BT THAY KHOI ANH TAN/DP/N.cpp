#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[MAXN],pre[MAXN];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int ans = LLONG_MIN,sum = 0,min_ps = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        sum += a[i];
        pre[i] = min(sum,pre[i-1]);
        if(i-k >= 0)ans = max(ans,sum-pre[i-k]);
    }
    cout << ans;
    return 0;
}