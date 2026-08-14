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
    ll k;
    cin >> k;
    if(k < 5) {
        cout << k * 30;
        return 0;
    }
    ll n = k / 5;
    ll ans = (5+n*5)*((n*5-5)/5+1)/2;
    cout << ans * 30 + (k%5)*(n+1)*30;
    return 0;
}