#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    ll max1 = -1e10;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        if(a[i] % 3 != 0) {
            ll tong = 0;
            while(a[i] % 3 !=0 && i <= n) {
                tong += a[i];
                max1 = max(tong,max1);
                if(tong < 0) tong = 0;
                i++;
            }
        }
    }
    cout << max1;
    return 0;
}