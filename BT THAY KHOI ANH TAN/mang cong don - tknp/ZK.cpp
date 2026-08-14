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
    ll n,m,k;
    cin >> n >> m >> k;
    ll l = 1,r = n*m,ans = 0;
    while(l <= r) {
        ll mid = (l+r)/2;
        ll d = 0;
        for(ll i = 1;i <= n;i++) {
            d += min(m,mid/i);
        }
        if(d >= k) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}