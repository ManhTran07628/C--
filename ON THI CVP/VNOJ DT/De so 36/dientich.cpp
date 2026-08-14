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
    #define taskname "dientich"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll r;
    cin >> r;
    ll ans = 0;
    for(ll i = 1;i <= 10000;i++) {
        for(ll j = 1;j <= 10000;j++) {
            if(sqrt(i*i+j*j) <= r) {
                ans = max(ans,i*4*j);
            }
        }
    }
    cout << ans;
    return 0;
}