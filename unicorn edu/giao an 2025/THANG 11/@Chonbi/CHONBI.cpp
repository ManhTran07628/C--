#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<ll,ll>
const int MM = 1e5+7;
int n,m;
pii a[MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "chonbi"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        cin >> a[i].fi >> a[i].se;
    }
    sort(a+1,a+m+1,[] (pii a,pii b){
        return a.se > b.se;
    });
    ll res = 0;
    for(int i = 1;i <= m;i++) {
        if(n >= a[i].fi) {
            res += 1ll * a[i].fi * a[i].se;
            n -= a[i].fi;
        }
        else {
            res += n * a[i].se;
            break;
        }
    }
    cout << res;
    return 0;
}