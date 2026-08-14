#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("TOPCA.inp","r",stdin);
    freopen("TOPCA.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll L = 1,R = 1e4,cachchia = 0;
    while(L <= R) {
        ll mid = (L+R)/2;
        ll dem = n;
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            ans += a[i] / mid;
            if(a[i] % mid != 0) {
                ans = ans + 1;
            }
        }
        if(ans <= k) {
            cachchia = mid;
            R = mid - 1;
        }
        else {
            L = mid + 1;
        }
    }
    cout << cachchia;
    return 0;
}





