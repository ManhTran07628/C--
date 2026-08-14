#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    freopen("hoakieng.inp","r",stdin);
    freopen("hoakieng.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    ll dem = 0;
    while(n--) {
        ll m,p,q;
        cin >> m >> p >> q;
        ll max1 = max(m,max(p,q));
        ll max3 = min(m,min(p,q));
        ll max2 = m+p+q - max1 - max3; // 7 6 5
        ll cl12 = abs(max1 - max2);
        ll cl13 = abs(max1 - max3);
        ll cl23 = abs(max2 - max3);
        if(cl13 > k) {
            if(cl12 > k && cl23 > k) {
                dem += 2;
            }
            else {
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}
