#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e5+7;
ll x[MAXN];
ll n;
ll doan1(ll p)
{
    multiset<ll> ms;
    ll ans = 0,l = 1,r = 1;
    for (ll l = 1; l <= n;l) {
        while (r <= n) {
            ms.insert(x[r]);
            ll val = *ms.rbegin()-*ms.begin();
            if (val > p) {
                ms.erase(ms.find(x[r]));
                break;
            }
            r++;
        }
        ans += (r - l);
        ms.erase(ms.find(x[l])); 
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ll a,b;
    cin >> a >> b;
    for(int i = 1;i <= n;i++) {
        cin >> x[i];
    }
    ll ans = 0;
    ans = doan1(b)-doan1(a-1);
    cout << ans;
    return 0;
}
