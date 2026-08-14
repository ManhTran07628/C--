#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
vector<ll> lt;
int main()
{
    freopen("BAI4.inp","r",stdin);
    freopen("BAI4.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    ll max1 = -1e9,vtd = -1e9,vtc = -1e9;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
        if(i >= k) {
            ll tmp = b[i] - b[i-k];
            if(tmp >= max1 && vtd <= i-k) {
                vtd = i-k;
                max1 = tmp;
                vtc = i;
            }
        }
    }
    cout << max1 << endl;
    for(int i = vtd+1;i <= vtc;i++) {
        cout << i << " ";
    }
    return 0;
}


