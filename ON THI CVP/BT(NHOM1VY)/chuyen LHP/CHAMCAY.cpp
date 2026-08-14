#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
pair<ll,ll> b[MAXN],c[MAXN];
set<pair<ll,ll>> s;
ll n,m,cay = 0;

void xuly()
{
    sort(b+1,b+m+1,greater<pair<ll,ll>>());
    for(int i = 1;i <= m;i++) {
        if(b[i-1].fi >= b[i].fi && b[i-1].se <= b[i].se) {
            b[i].fi = b[i-1].fi;
            b[i].se = b[i-1].se;
        }
        s.insert({b[i].fi,b[i].se});
    }
    m = s.size();
    int i = 1;
    for(auto p:s) {
        c[i].fi = p.fi;
        c[i].se = p.se;
        i++;
    }
    sort(c+1,c+m+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        cay = max(cay,a[i]);
    }
    cin >> m;ll R = 0;
    for(int i = 1;i <= m;i++) {
        cin >> b[i].fi >> b[i].se;
        R = max(R,b[i].fi);
    }  
    xuly();
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ll p = lower_bound(c+1,c+m+1,make_pair(a[i],0ll)) - c;
        ans += c[p].se;
    }
    cout << ans;
    return 0;
}