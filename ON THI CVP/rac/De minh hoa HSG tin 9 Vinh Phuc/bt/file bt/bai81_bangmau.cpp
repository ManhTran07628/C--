#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
set<ll> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BANGMAU"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll dem = 0;
        for(int i = 1;i <= n;i++) {
            ll a1;
            cin >> a1;
            a.insert(a1);
        }
        cout << n-a.size() << '\n';
        a.clear();
    }
    return 0;
}