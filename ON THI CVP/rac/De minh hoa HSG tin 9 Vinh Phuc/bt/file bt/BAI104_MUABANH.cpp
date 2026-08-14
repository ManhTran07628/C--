#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BANH"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,k;
    cin >> n >> m >> k;
    ll t;
    if(n >= k) {
        t = n * m * 0.8;
    }
    else {
        ll ans = k * m * 0.8;
        t = min(ans,n*m);
    }
    cout << t;
    return 0;
}
