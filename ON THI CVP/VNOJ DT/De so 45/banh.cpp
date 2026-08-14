#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "banh"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m,k;
    cin >> n >> m >> k;
    ll ans = n*m;
    if(n >= k) {
        ans = ans * 0.8;
    }
    else {
        ll x = k*m*0.8;
        ans = min(ans,x);
    }
    cout << ans;
    return 0;
}