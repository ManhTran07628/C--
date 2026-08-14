#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N],b[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("DOANNT.inp","r",stdin);
    freopen("DOANNT.out","w",stdout);
    for(ll i = 0;i <= N;i++) {
        a[i] = 1;
    }
    a[0]=a[1]=0;
    for(ll i = 1;i <= N;i++) {
        if(a[i] == 1) {
            for(ll j = i*i;j <= N;j+=i) {
                a[j] = 0;
            }
        }
        b[i] = b[i-1] + a[i];
    }
    ll Q;
    cin >> Q;
    while(Q--) {
        ll l,r;
        cin >> l >> r;
        cout << b[r] - b[l-1] << endl;
    }
    return 0;
}
