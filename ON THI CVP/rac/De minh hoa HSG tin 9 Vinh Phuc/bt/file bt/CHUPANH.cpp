#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 1;
ll a[N],b[N];
map<ll,ll> c;
int main() {
    freopen("CHUPANH.inp","r",stdin);
    freopen("CHUPANH.out","w",stdout);
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin >> b[i];
        c[b[i]]=1;
    }
    ll dodai = 0,vtd = 0,vtc = 0;
    for(int i = 1;i <= n;i++) {
        if(c[a[i]] == 1) {
            ll L = i;
            while(c[a[i]] == 1 && i <= n) {
                i++;
            }
            ll R = i;
            if(R - L > dodai) {
                dodai = R - L;
                vtd = L;
                vtc = R;
            }
        }
    }
    cout << dodai << endl;
    cout << vtd << " " << vtc-1;
    return 0;
}

