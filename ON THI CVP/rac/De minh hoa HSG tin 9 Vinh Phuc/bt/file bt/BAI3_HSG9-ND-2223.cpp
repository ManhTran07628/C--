#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
pair<ll,ll> a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "PHIEU"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        ll a1;
        cin >> a1;
        a[i] = {a1,i};
    }
    sort(a+1,a+n+1);
    ll dem = 1,vt = a[0].second;
    for(int i = 1;i <= n;i++) {
        if(a[i].second > vt) {
            vt = a[i].second;
        }
        else {
            vt = a[i].second;
            dem++;
        }
    }
    cout << dem;
    return 0;
}
