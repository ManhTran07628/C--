#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N],c[N];
int main() {
    freopen("TAMGIAC.inp","r",stdin);
    freopen("TAMGIAC.out","w",stdout);
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++) {
        cin >> b[i];
    }
    for(int i = 0;i < n;i++) {
        cin >> c[i];
    }
    sort(a,a+n);
    sort(b,b+n);
    sort(c,c+n);
    ll dem = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            ll tmp = upper_bound(c,c+n,a[i]+b[j]) - c;
            dem += tmp;
        }
    }
    cout << dem;
    return 0;
}

