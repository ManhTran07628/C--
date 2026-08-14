#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;


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
    ll t = 3;
    while(t--) {
        ll n;
        cin >> n;
        if(n % 5 == 0) n--;
        if(n % 2 == 0) n--;
        ll x = n / 10;
        ll z = n % 10;
        ll ans;
        if(x % 2 == 0) {
            ans = 1;
            for(int i = 1;i <= z;i++) {
                if(i % 2 != 0 && i % 5 != 0) {
                    ans *= i;
                }
            }
        }
        else {
            ans = 9;
            for(int i = 1;i <= z;i++) {
                if(i % 2 != 0 && i % 5 != 0) {
                    ans *= i;
                }
            }
        }
        cout << ans % 10 << '\n';
    }
    return 0;
}
// 2 4 5 6 8 