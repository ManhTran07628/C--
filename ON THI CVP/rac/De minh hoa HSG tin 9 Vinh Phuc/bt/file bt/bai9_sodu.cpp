#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll tmp = 1e6;
int main() {
    freopen("bai01.inp","r",stdin);
    freopen("bai01.out","w",stdout);
    ll a,b,c;
    cin >> a >> b >> c;
    ll kq = 1;
    a = a % c;
    while(b != 0) {
        if(b % 2 == 1) {
            kq = kq * a % c ;
        }
        b /= 2;
        a = a * a % c;
    }
    cout << kq;
    return 0;
}
