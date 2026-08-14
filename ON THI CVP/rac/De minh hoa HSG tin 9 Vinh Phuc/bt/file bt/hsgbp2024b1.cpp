#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6 + 7;
ll a[N];
ll ktrasnt(ll k)
{
    if(k < 2) {
        return 0;
    }
    for(int j = 2;j <= sqrt(k);j++) {
        if(k % j == 0) {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ll n;
    cin >> n;
    int dem = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++) {
        if(ktrasnt(a[i]) == 1) {
            dem++;
        }
    }
    cout << dem;
    return 0;
}


