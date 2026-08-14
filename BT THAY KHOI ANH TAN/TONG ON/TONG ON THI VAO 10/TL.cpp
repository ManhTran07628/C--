#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
pair<int,int> a[MAXN];
int ps[MAXN];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i++) ps[i] = ps[i-1] + a[i].se;
    int pre_max = a[1].fi,ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = max(ans,ps[i]-a[i].fi+pre_max);
        pre_max = max(pre_max,a[i+1].fi-ps[i]);
    }
    cout << ans;
    return 0;
}