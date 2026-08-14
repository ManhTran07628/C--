#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
ll a[N];
const int ma = 1e7+1;
int main() {
    freopen("HANGXOM.inp","r",stdin);
    freopen("HANGXOM.out","w",stdout);
    for(ll i = 0;i <= N;i++) {
        a[i] = 1;
    }
    a[0]=a[1]=0;
    for(ll i = 2;i <= N;i++) {
        if(a[i] == 1) {
            for(ll j = i*i;j <= N;j+=i) {
                a[j] = 0;
            }
        }
    }
    ll L,R;
    cin >> L >> R;
    ll dem = 0;
    for(int i = L;i <= R;i++) {
        if(a[i] == 1 && a[i+2] == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}
