#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    ll n,s;
    cin >> n >> s;
    for(ll i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    if(b[n] - b[0] < s) {
        cout << 0;
        return 0;
    }
    ll j = 0,tong = 0,dem = 1e9;
    for(ll i = 0;i < n;i++) {
        while(b[j] - b[i] < s && j <= n) {
            j++;
        }
        if(b[j] - b[i-1] >= s) {
            dem = min(dem,j-i);
        }
    }
    cout << dem;
    return 0;
}






