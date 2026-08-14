#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 5;
ll a[N],b[N],c[N];
int main() {
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        a[i] = a[i-1] + a[i];
        b[i] = b[i-1] + b[i];
        c[i] = c[i-1] + c[i];
        if(a1 == 1) a[i]++;
        if(a1 == 2) b[i]++;
        if(a1 == 3) c[i]++;
    }
    while(q--) {
        ll l,r;
        cin >> l >> r;
        cout << a[r] - a[l-1] << " ";
        cout << b[r] - b[l-1] << " ";
        cout << c[r] - c[l-1] << " ";
        cout << endl;
    }
    return 0;
}




