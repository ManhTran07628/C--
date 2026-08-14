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
    ll n;
    cin >> n;
    ll ans = 0;
    if(n % 3 == 0) ans = (n/3)*7;
    if(n % 3 == 1) ans = (n/3-1)*7+4;
    else ans = (n/3-1)*7+5;
    cout << ans;
    return 0;
}