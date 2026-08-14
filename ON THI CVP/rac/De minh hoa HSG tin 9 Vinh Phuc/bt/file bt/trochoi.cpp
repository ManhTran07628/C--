#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "trochoi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n,x,y;
    cin >> m >> n >> x >> y;
    ll k = x / __gcd(x,y) * y;
    cout << (n/k) - (m-1)/k;
    return 0;
}