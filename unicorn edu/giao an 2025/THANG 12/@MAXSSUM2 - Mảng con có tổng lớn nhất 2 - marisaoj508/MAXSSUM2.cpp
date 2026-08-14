#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N],trai[N],phai[N];
int main()
{
    ll tiento = 0,tmp = -1e18;
    ll n;
    cin >> n;
    trai[0] = -1e18;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        tiento = tiento + a[i];
        tmp = max(tmp,tiento);
        trai[i] = max(trai[i-1],tmp);
        if(tiento <= 0) {
            tiento = 0;
        }
    }
    phai[n+1] = -1e18;
    tiento = 0,tmp = -1e18;
    for(int i = n;i >= 1;i--) {
        tiento = tiento + a[i];
        tmp = max(tmp,tiento);
        phai[i] = max(phai[i+1],tmp);
        if(tiento <= 0) {
            tiento = 0;
        }
    }
    ll max1 = -1e18;
    for(int i = 1;i <= n;i++) {
        max1 = max(max1,trai[i]+phai[i+1]);
    }
    cout << max1;
    return 0;
}