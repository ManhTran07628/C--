#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

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
    ll a,b,c;
    cin >> a >> b >> c;
    ll dem = 0;
    for(ll i = 1;i*a <= c;i++) {
        ll ans = c - i*a;
        ans = ans / b;
        if(ans * b + a * i == c && ans > 0) {
            dem++;
            cout << i << " " << ans << '\n';
        }
    }
    cout << dem;
    return 0;
}