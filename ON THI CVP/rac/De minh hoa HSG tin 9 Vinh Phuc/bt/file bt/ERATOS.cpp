#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;

ll snt(ll k)
{
    for(int i = 2;i <= sqrt(k);i++) {
        if(k%i==0) return 0;
    }
    return 1;
}

ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    if(n <= 1e7) {
        ll lt = 0;
        for(ll i = 2;i <= n;i++) {
            a[i] = 1;
        }
        for(int i = 2;i <= sqrt(n);i++) {
            if(a[i]) {
                for(ll j = i*i;j <= n;j+=i) {
                    a[j] = 0;
                    if(b[j] == 0) {
                        lt = j;
                        b[j]++;
                    }
                }
            }
            if(b[i] == 0 && a[i] == 0) {
                lt = i;
                b[i]++;
            }
        }
        cout << lt;
        return 0;
    }
    ll lt = 0;
    for(int i = 2;i <= sqrt(n);i++) {
        if(snt(i)==1) {
            lt = i;
        }
    }
    ll tmp = n / lt;
    while(!snt(tmp)) tmp--;
    cout << tmp * lt;
    return 0;
}
