#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
pair<ll,ll> a[N];

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
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+n+1);
    ll l = a[1].fi,r = a[1].se;
    for(int i = 2;i <= n;i++) {
        if(a[i].se <= r) {
            r = a[i].se;
        }
        else {
            cout << l << ' ' << r << '\n';
            l = a[i].fi;r = a[i].se;
        }
    }
    cout << l << ' ' << r << '\n';
    return 0;
}