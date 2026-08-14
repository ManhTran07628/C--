#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e4+2;
vector<ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tontai"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll k;
    cin >> k;
    for(ll i = 1;i <= 1000;i++) {
        for(ll j = 1;j <= 1000;j++) {
            ll ans = (i*i) + (j*j);
            a.push_back(ans);
        }
    }
    sort(a.begin(),a.end());
    cout << a[k-1];
    return 0;
}