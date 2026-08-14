#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll tmp = 1e6;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SOTHUK"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,m,k;
        cin >> n >> m >> k;
        set<ll> a;
        for(int i = 1;i <= m;i++) {
            ll a1;
            cin >> a1;
            a.insert(a1);
        }
        

    }
    return 0;
}