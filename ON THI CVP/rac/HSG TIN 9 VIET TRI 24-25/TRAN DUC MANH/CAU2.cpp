#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll s;


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
    for(ll i = 1;i <= 100;i++) {
        for(ll j = 1;j <= 100;j++) {
            for(ll k = 1;k <= 100;k++) {
                for(ll h = 1;h <= 100;h++) {
                    a[i*i+j*j+k*k+h*h] = 4;
                }
            }
        }
    }
    for(ll i = 1;i <= 100;i++) {
        for(ll j = 1;j <= 100;j++) {
            for(ll k = 1;k <= 100;k++) {
                a[i*i+j*j+k*k] = 3;
            }
        }
    }
    for(ll i = 1;i <= 100;i++) {
        for(ll j = 1;j <= 100;j++) {
            a[i*i+j*j] = 2;
        }
    }
    for(ll i = 1;i <= 100;i++) {
        a[i*i] = 1;
    }
    ll t;
    cin >> t;
    while(t--)
    {
        ll s;
        cin >> s;
        cout << a[s] << '\n';
    }
    return 0;
}