#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 7;
ll a[N];
pair<pair<ll,ll>,string> p[N];
map<ll,ll> m;
multiset<ll> ms;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,g;
    cin >> n >> g;
    for(ll i = 1;i <= n;i++) {
        cin >> p[i].fi.fi >> p[i].fi.se >> p[i].se;
        m[p[i].fi.se] = g;
        ms.insert(g);
    }
    ll ans = 0,max1 = g;
    sort(p+1,p+n+1);
    for(ll i = 1;i <= n;i++) {
        ll so = 0;
        if(p[i].se[0] == '+') so = p[i].se[1] - '0';
        else so = -(p[i].se[1]-'0');
        ms.erase(ms.find(m[p[i].fi.se]));
        m[p[i].fi.se] += so;
        ms.insert(m[p[i].fi.se]);
        ll kt = 1;
        auto gt = ms.rbegin();
        if(*gt != max1) {
            ans++;
            max1 = *gt;
        }
    }
    cout << ans << '\n';
    return 0;
}

