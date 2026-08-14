#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "CAU1"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll x,y;
    cin >> x >> y;
    ll dem = 0;
    ll ans = __gcd(x,y);
    for(int i = 1;i <= sqrt(ans);i++) {
        if(ans % i == 0) {
            dem++;
            if(ans / i != i) {
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}