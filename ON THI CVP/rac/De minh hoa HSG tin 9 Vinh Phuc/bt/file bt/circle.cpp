#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];

ll trai(ll a[],ll n,ll i)
{
    ll test = 1,kt = a[i];
    for(int j = i+1;j < i+n;j++) {
        if(kt+1 != a[j]) {
            test = 0;
            break;
        }
        kt = a[j];
    }
    return test;
}
ll phai(ll a[],ll n,ll i)
{
    ll test = 1,kt = a[i];
    for(int j = i+1;j < i+n;j++) {
        if(kt-1 != a[j]) {
            test = 0;
            break;
        }
        kt = a[j];
    }
    return test;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "circle"
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
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
        }
        for(int i = n+1;i <= n+n;i++) {
            a[i] = a[i-n];
        }
        ll dem = 0;
        for(int i = 1;i <= n;i++) {
            if(trai(a,n,i) || phai(a,n,i)) {
                dem = 1;
                break;
            }
        }
        if(dem) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
