#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<ll,ll>
const int MM = 2e5 + 7;
int n;
pii a[MM];

namespace subtask1
{
    bool check()
    {
        for(int i = 1;i < n;i++) if(a[i].fi != a[i+1].fi) return 0;
        return 1;
    }

    void solve()
    {
        sort(a+1,a+n+1,[] (pii x,pii y){return x.se < y.se;});
        ll sum = a[1].fi;
        cout << sum << '\n';
        for(int i = 1;i <= n - 1;i++) {
            sum += a[i].se;
            cout << sum << '\n';
        }
    }
}

namespace subtask2
{
    bool check()
    {
        for(int i = 1;i < n;i++) if(a[i].se != a[i+1].se) return 0;
        return 1;
    }

    void solve()
    {
        sort(a+1,a+n+1,[] (pii x,pii y){return x.fi < y.fi;});
        ll sum = a[1].fi;
        cout << sum << '\n';
        for(int i = 1;i <= n - 1;i++) {
            sum += a[i].se;
            cout << sum << '\n';
        }
    }
}

namespace sol
{
    pii suffix[MM];

    void solve()
    {
        sort(a+1,a+n+1, [] (pii x,pii y) {
            if(x.se != y.se) return x.se < y.se;
            return x.fi > y.fi;
        });

        ll sum = 0, lead = 1;
        for(int i = 2;i <= n;i++) {
            if(a[i].fi < a[lead].fi) lead = i;
        }

        suffix[n + 1] = {oo,n + 1};
        for(int i = n;i >= 1;i--) {
            if(a[i].fi < suffix[i + 1].fi) suffix[i] = {a[i].fi,i};
            else suffix[i] = suffix[i + 1];
        }

        cout << a[lead].fi << '\n';
        int cnt = n - 1;
        for(int i = 1;i <= n && cnt > 0;i++, cnt--) {
            if(i == lead) {
                int new_lead = suffix[i + 1].se;
                if(a[lead].fi + a[i + 1].se > a[new_lead].fi + a[lead].se) {
                    lead = new_lead;
                    sum += a[lead].se;
                }
                else {
                    sum += a[i + 1].se;
                    i++;
                }
                cout << a[lead].fi + sum << '\n';
            }
            else { 
                sum += a[i].se;
                cout << a[lead].fi + sum << '\n';
            }
        }
    }
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
    for(int i = 1;i <= n;i++) cin >> a[i].fi >> a[i].se;
    if(subtask1::check()) subtask1::solve();
    else if(subtask2::check()) subtask2::solve();
    else sol::solve();
    return 0;
}