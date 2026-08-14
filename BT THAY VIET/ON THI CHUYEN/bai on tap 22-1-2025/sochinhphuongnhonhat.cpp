#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 3e7+7;
vector<ll> v;
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
    ll k;
    cin >> k;
    if(k == 0) {
        cout << 0;
        return 0;
    }
    ll ans = 1e18;
    for(ll i = 1;i <= sqrt(abs(k));i++) {
        if(k % i == 0) {
            ll m = abs(k)/i;
            for(ll x : {i,m}) {
                ll y = abs(k)/x;
                if((x+y) % 2 == 0) {
                    ll b = (x+y)/2;
                    ll a = (x-y)/2;
                    ans = min({});
                }
            }
        }
    }
    if(ans == 1e18) cout << "none";
    else cout << ans;
    return 0;
}