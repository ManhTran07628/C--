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
    ll k,e,n;
    cin >> k >> e >> n;
    for(int i = 1;i <= n;i++) {
        ll x,f,c;
        cin >> x >> f >> c;
        ll st = (e-x+c);
        a[i].fi = st;
        a[i].se = f;
    }
    sort(a+1,a+n+1);
    ll cnt = 0,cash = 0;
    for(int i = 1;i <= n;i++) {
        if(cnt + a[i].se <= k) {
            cnt += a[i].se;
            cash += a[i].se*a[i].fi;
        }
        else {
            cash += (k-cnt)*a[i].fi;
            break;
        }
    }
    cout << cash;
    return 0;
}