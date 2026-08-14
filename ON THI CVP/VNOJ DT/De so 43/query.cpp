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
    #define taskname "query"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    while(q--) {
        ll k;
        cin >> k;
        if(k == 1) {
            ll p,m,x;
            cin >> p >> m >> x;
            for(int i = p;i <= m;i++) {
                a[i] += x;
            }
        }
        else {
            ll u,v;
            cin >> u >> v;
            ll ans = 0;
            for(int i = u;i <= v;i++) {
                ans += a[i];
            }
            cout << ans << '\n';
        }
    }

    return 0;
}
