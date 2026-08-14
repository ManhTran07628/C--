#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main() {
    //freopen("tongchan.inp","r",stdin);
    //freopen("tongchan.out","w",stdout);
    ll n,dem = 0,dem1 = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> a[i];
    for (int i = 0;i < n;i++) {
        if (a[i] % 2 == 0) {
            dem++;
        }
    }
    for (int i = 0;i < n;i++) {
        if (a[i] % 2 != 0) {
            dem1++;
        }
    }
    ll test = min(dem1,dem);
    cout << test;
    return 0;
}
