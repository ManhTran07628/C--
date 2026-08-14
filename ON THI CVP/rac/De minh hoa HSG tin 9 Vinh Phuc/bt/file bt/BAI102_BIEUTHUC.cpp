#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BIEUTHUC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll a,b,c;
    cin >> a >> b >> c;
    ll a1 = max({a,b,c});
    ll c3 = min({a,b,c});
    ll b2 = a+b+c-a1-c3;
    ll max1 = max({a1+b2+c3,a1-b2+c3,a1+b2-c3,a1-b2-c3});
    cout << max1;
    return 0;
}