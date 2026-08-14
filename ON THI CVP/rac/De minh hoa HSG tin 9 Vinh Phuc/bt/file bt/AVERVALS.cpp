1#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main() {
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll dem = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = i;j <= n;j++) {
            ll ans = (b[j] - b[i-1]);
            if(ans % (j-i+1) == 0) {
                for(int k = i;k <= j;k++) {
                    if(b[k] - b[k-1] == (ans / (j-i+1))) {
                        dem++;
                        break;
                    }
                }
            }

        }
    }
    cout << dem;
    return 0;
}
