#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "nenso"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    while(n > 9) {
        ll ans = 0;
        ll n1 = n;
        while(n1 > 0) {
            ans += n1 % 10;
            n1 /= 10;
        }
        n = ans;
    }
    cout << n;
    return 0;
}