#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;

ll tinh(ll n)
{
    return n/2+n/3-n/6;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll k;
    cin >> k;
    ll l = 1,r = 1e18,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(tinh(mid) >= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}