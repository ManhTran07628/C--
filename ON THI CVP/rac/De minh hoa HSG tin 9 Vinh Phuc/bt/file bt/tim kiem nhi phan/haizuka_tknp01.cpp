#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
map<ll,ll> b;

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
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]] = 1;
    }
    ll q;
    cin >> q;
    while(q--)
    {
        ll x;
        cin >> x;
        ll fi = lower_bound(a+1,a+n+1,x) - a;
        if(b[x] == 0) cout << -1 << '\n';
        else cout << fi << '\n';
    }
    return 0;
}