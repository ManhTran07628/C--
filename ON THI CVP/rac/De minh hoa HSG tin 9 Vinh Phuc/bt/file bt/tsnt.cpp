#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<ll,ll> b;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "TSNT"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    // ll tong1 = 80;
    // ll tong = 80;
    // for(int i = 2;i <= sqrt(tong);i++) {
    //     while(tong % i == 0) {
    //         tong /= i;
    //         b[i]++;
    //     }
    // }
    // if(tong > 1) b[tong]++;
    // for(int i = 1;i <= tong1;i++) {
    //     if(b[i] != 0) {
    //         cout << i << " " << b[i] << '\n';
    //     }
    // }



    ll n;
    cin >> n;
    ll somu = 0;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        ll ans = a[i];
        for(int j = 2;j <= sqrt(ans);j++) {
            while(ans % j == 0) {
                somu++;
                ans /= j;
            }
        }
        if(ans > 1) somu++;
    }
    ll max1 = 1e9;
    for(int i = 1;i <= n;i++) {
        ll ans = a[i];
        ll kq = 0;
        for(int j = 2;j <= sqrt(ans);j++) {
            while(ans % j == 0) {
                kq++;
                ans /= j;
            }
        }
        if(ans > 1) kq++;
        max1 = min(max1,somu-kq);
    }
    cout << max1;
    return 0;
}
