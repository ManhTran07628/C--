#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    freopen("dauthau.inp","r",stdin);
    freopen("dauthau.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    ll max1 = -1e9;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        a[i] = a[i] / 2;
        max1 = max(max1,a[i]);
    }
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        if(a[i] == max1) dem++;
    }
    if(dem < k-1) {
        cout << max1;
    }
    else {
        cout << max1 + 1;
    }
    return 0;
}



