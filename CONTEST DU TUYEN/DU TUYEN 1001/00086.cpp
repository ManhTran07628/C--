#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e6+7;
int n,k;
ll a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a+1,a+n+1,greater<ll>());
    ll cnt1 = 0,cnt2 = 0,res1 = 0,res2 = 0;
    for(int i = 1;i <= n;i++) {
        if(cnt1 + 1 <= k && a[i] % 2) {
            res1 += a[i];
            cnt1++;
        }
        if(cnt2 + 1 <= k && a[i] % 2 == 0) {
            res2 += a[i];
            cnt2++;
        }
    }
    ll res = 0;
    if(cnt1 == k) res = res1;
    if(cnt2 == k) res = max(res,res2);
    cout << res;
    return 0;
}