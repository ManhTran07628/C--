#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "Sumdivisors"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll tong = 0;
        for(int i = 1;i <= sqrt(n);i++) {
            if(n % i == 0) {
                for(int j = 1;j <= sqrt(i);j++) {
                    if(i % j == 0) {
                        tong += j;
                        if(i / j != j) tong += i / j;
                    }
                }
                if(n / i != i) {
                    for(int j = 1;j <= sqrt(n/i);j++) {
                    if(n/i % j == 0) {
                        tong += j;
                        if(n/i / j != j) tong += n/i / j;
                    }
                }
            }
        }
        }
        cout << tong << '\n';
    }
    return 0;
}