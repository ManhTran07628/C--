#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N];
int main() {
    freopen("HANGRAO.inp","r",stdin);
    freopen("HANGRAO.out","w",stdout);
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    ll min1 = 1e9,dem = 0;
    for(int i = 0;i < n;i++) {
        ll ans = 0;
        for(int j = 0;j < n;j++) {
            ans += abs(a[i]-a[j]);
        }
        if(min1 > ans) {
            min1 = ans;
            dem = a[i];
        }
        else if(min1 == ans) {
            if(dem < a[i]) {
                dem = a[i];
            }
        }
    }
    cout << dem << endl << min1;
    return 0;
}

