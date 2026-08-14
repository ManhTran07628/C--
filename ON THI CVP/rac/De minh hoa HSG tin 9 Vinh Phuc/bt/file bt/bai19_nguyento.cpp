#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
ll sang[N];
ll tmp = 1e7;
int main() {
    freopen("nguyento.inp","r",stdin);
    freopen("nguyento.out","w",stdout);
    ll a,b;
    cin >> a >> b;
    for(ll i = 0;i <= tmp;i++) {
        sang[i] = 1;
    }
    sang[0] = sang[1] = 0;
    ll dem = 0;
    for(ll i = 1;i <= tmp;i++) {
        if(sang[i] == 1) {
            for(ll j = i*i;j <= tmp;j+=i) {
                sang[j] = 0;
            }
        }
    }
    for(ll i = a;i <= b;i++) {
        if(sang[i] == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}


