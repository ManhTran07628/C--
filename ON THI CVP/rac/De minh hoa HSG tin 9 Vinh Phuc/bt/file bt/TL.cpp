#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[501][501],b[501][501];
ll tmp = 1e6;
int main() {
    ll n,m;
    cin >> n >> m;
    ll kq = -1e18;
    for(ll i = 1;i <= n;i++) {
        for(ll j = 1;j <= m;j++) {
            cin >> a[i][j];
            b[i][j] = b[i][j-1] + a[i][j];
            kq = max(kq,b[i][j]);
            if(b[i][j] < 0) {
                b[i][j] = 0;
            }
        }
    }
    cout << kq;
    return 0;
}

