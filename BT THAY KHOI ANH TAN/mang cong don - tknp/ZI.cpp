#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while(q--) {
        ll k;
        cin >> k;
        ll l = 1,r = 1e9,ans = 0;
        while(l <= r) {
            ll mid = (l+r)/2;
            ll sum = (mid+1)*mid/2;
            if(sum <= k) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}