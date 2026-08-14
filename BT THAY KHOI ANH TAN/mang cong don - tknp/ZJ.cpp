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
    int q;
    cin >> q;
    while(q--) {
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        ll l = 0,r = 1e4,ans = -1;
        while(l <= r) {
            ll mid = (l+r)/2;
            ll sum = a*mid*mid*mid*mid+b*mid*mid+c;
            if(sum <= d) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << ans << '\n';
    }
    return 0;
}