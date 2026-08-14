#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N];
// (l + i - 1)/i*i
ll sodautien(ll l,ll i) {
    return (l+i-1)/i*i; // tim so chia het cho i nho nhat lon hon l
}
ll ktrasnt(ll k)
{
    for(int i = 2;i <= sqrt(k);i++) {
        if(k % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll L,R;
    cin >> L >> R;
    for(ll i = 0;i <= R-L+1;i++) {
        a[i] = 1;
    }
    a[0]=a[1]=0;
    for(ll i = 2;i <= sqrt(R);i++) {
        for(ll j = max(i*i,sodautien(L,i));j <= R;j+=i) {
            a[j-L] = 0;
        }
    }
    if(L <= 2) {
        cout << 2 << " ";
    }
    if(ktrasnt(L) == 1 && L > 2) {
        cout << L << " ";
    }
    for(ll i = max(2ll,L);i <= R;i++) {
        if(a[i-L] == 1) {
            cout << i << " ";
        }
    }
    return 0;
}

