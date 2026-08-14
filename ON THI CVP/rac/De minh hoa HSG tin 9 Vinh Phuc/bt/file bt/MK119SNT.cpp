#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
int main() {
    for(ll i = 1;i <= N;i++) {
        a[i] = 1;
    }
    a[0]=a[1]=0;
    for(ll i = 1;i <= N;i++) {
        if(a[i] == 1) {
            for(ll j = i * i;j <= N;j+=i) {
                a[j] = 0;
            }
        }
    }
    for(ll i = 1;i <= N;i++) {
        ll tmp = 0;
        if(a[i] == 1) tmp = 1;
        b[i] = b[i-1] + tmp;
    }
    ll T;
    cin >> T;
    while(T--) {
        ll l,r;
        cin >> l >> r;
        ll ans = b[r] - b[l-1];
        cout << ans << endl;
    }
    return 0;
}
