#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 50 + 7;
int n;
pii p[MM];

bool cmp(pii a,pii b)
{
    ll x = a.fi * b.se, y = b.fi * a.se;
    return x > y;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) cin >> p[i].fi;
    for(int i = 1;i <= n;i++) cin >> p[i].se;
    sort(p+1,p+n+1,cmp);
    for(int i = 1;i <= n;i++) cout << p[i].fi << ' ' << p[i].se << '\n';
    return 0;
}