#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int dp[MAXN];

struct dl
{
    int l,r,cost;
} a[MAXN];

bool cmp(dl a,dl b)
{
    if(a.l != b.l) return a.l <= b.l;
    return a.r <= b.r;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].l >> a[i].r >> a[i].cost;
    }
    sort(a+1,a+n+1,cmp);
    for(int i = 1;i <= n;i++) {
        dp[i] = a[i].cost;
        for(int j = i-1;j >= 1;j--) {
            if(a[i].l >= a[j].r) {
                dp[i] = max(dp[i],dp[j]+a[i].cost);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,dp[i]);
    }
    cout << ans;
    return 0;
}