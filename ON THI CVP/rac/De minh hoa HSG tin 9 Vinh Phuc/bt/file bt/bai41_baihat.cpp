#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N],b[N];
int main()
{
    freopen("BAIHAT.inp","r",stdin);
    freopen("BAIHAT.out","w",stdout);
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    ll vtd = 0,vtc = 0,max1 = -1e9;
    for(int i = k;i <= n;i++) {
        if(b[i] - b[i-k] > max1) {
            vtd = i-k+1;
            vtc = i;
            max1 = b[i] - b[i-k];
        }
    }
    cout << vtd << " " << vtc << " " << max1;
    return 0;
}


