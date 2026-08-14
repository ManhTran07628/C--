#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "minsum"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll G,L;
    cin >> G >> L;
    if(L % G != 0) {
        cout << -1;
        return 0;
    }
    ll n = L / G;
    ll tmp = 1e9;
    for(ll i = 1;i <= sqrt(n);i++) {
        if(n % i == 0) {
            tmp = min(tmp,n/i+i);
        }  
    }
    cout << tmp*G;
    return 0;
}
