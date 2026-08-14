#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll f[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "chinhphuong"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,b;
    cin >> a >> b;
    ll tong = 0;
    ll max1 = -1e9;
    for(ll i = ceil(sqrt(a));i <= sqrt(b);i++) {
        tong += i*i;
        ll tmp = i*i,dem = 0;
        for(ll j = 1;j <= sqrt(tmp);j++) {
            if(tmp % j == 0) {
                dem++;
                if(tmp / j != j) 
                    dem++;
            }
        }
        max1 = max(max1,dem);
    }
    cout << tong << '\n' << max1;
    return 0;
}