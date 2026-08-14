#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll l = 1,r = 1e15,ans = -1;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll sum = 0;
        for(int i = 1;i <= n;i++) {
            sum += a[i]*mid;
            if(sum > k) break;
        }
        if(sum <= k) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}