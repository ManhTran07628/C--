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
        cin >> a[i].se >> a[i].fi;
    }
    sort(a+1,a+n+1);
    ll cnt = 1,crr = a[1].fi,max1 = 1;
    for(int i = 2;i <= n;i++) {
        if(a[i].se >= crr) {
            crr = a[i].fi;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}