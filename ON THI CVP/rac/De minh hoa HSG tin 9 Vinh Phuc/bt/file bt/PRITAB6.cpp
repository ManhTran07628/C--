#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4 + 5;
ll a[1506][1506];
vector<ll> b;
ll ktsnt(ll k)
{
    if(k < 2) return 0;
    for(int i = 2;i <= sqrt(k);i++)
        if(k % i == 0) return 0;
    return 1;
}

int main() {
    ll n,m;
    ll tong = 0,dem = 0;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if(ktsnt(a[i][j])) {
                tong += a[i][j];
                dem++;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ll ans = a[i][j];
            if(a[i][j] != 0) {
                for(int h = 1;h <= 5;h++) {
                    ans = ans * 10 + a[i][j+h];
                    if(ktsnt(ans)) {
                        dem++;
                        tong += ans;
                    }
                }
                ans = a[i][j];
                for(int h = 1;h <= 5;h++) {
                    ans = ans * 10 + a[i+h][j];
                    if(ktsnt(ans)) {
                        dem++;
                        tong += ans;
                    }
                }
                ans = a[i][j];
                for(int h = 1;h <= 5;h++) {
                    ans = ans * 10 + a[i+h][j+h];
                    if(ktsnt(ans)) {
                        dem++;
                        tong += ans;
                    }
                }
            }
        }
    }
    cout << dem << " " << tong;
    return 0;
}
