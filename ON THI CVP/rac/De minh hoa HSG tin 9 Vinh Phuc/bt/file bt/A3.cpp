#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e7+7;
map<ll,ll> b;

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
    ll cnt = 0;
    for(ll i = 2;i * i <= n;i++) {
        if(n % i == 0) {
            cnt++;
            ll crr = 0;
            while(n % i == 0) {
                n /= i;
                crr++;
            }
            b[i] = crr;
        }
    }
    if(n > 1) {
        b[n]++;
        cnt++;
    }
    cout << cnt << '\n';
    for(auto it:b) {
        cout << it.fi << ' ' << it.se << '\n';
    }
    return 0;
}