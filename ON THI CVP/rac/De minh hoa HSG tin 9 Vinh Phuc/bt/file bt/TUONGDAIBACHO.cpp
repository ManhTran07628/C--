#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
int main() {
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    while(k--) {
        ll u,v;
        cin >> u >> v;
        cout << b[v] - b[u-1] << " ";
    }
    return 0;
}
