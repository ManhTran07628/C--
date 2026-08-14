#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ARRSUM"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,c;
    cin >> n >> c;
    if(c > 0) {
        ll max1 = -1e9,tong = 0,tong1 = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            tong += a[i];
            tong1+=a[i];
            max1 = max(max1,tong);
            if(tong < 0) tong = 0;
        }
        if(max1 < 0) cout << tong1;
        else {
            cout << tong1 - max1 + max1*c;
        }
    }
    else {
        ll min1 = 1e9,tong = 0,tong1 = 0;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            tong += a[i];
            min1 = min(min1,tong);
            if(tong > 0) tong = 0;
            tong1 += a[i];
        }
        if(min1 > 0) {
            cout << tong1;
        }
        else {
            cout << tong1 - min1 + min1*c;
        }
    }
    return 0;
}

