#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
map<ll,ll> b;
int main() {
    freopen("subseg.inp","r",stdin);
    freopen("subseg.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    ll i = 1,j = 1;
    ll kq = 0,dem = 0;
    while(j <= n) {
        if(b[a[j]] == 0) {
            dem++;
        }
        b[a[j]]++;
        if(dem > k) {
            while(dem > k) {
                b[a[i]]--;
                if(b[a[i]] == 0) {
                    dem--;
                }
                i++;
            }
        }
        kq += (j - i + 1);
        j++;
    }
    cout << kq;
    return 0;
}
