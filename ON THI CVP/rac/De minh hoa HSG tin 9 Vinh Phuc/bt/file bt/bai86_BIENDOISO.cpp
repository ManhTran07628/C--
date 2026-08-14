#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
vector<ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "BIENDOISO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    for(ll i = 0;i <= 39;i++) {
        for(ll j = 0;j <= 39;j++) {
            if(i != j) {
                ll ans = pow(2,i) + pow(2,j);
                a.push_back(ans);
            }
        }
    }
    sort(a.begin(),a.end());
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll vt1 = lower_bound(a.begin(),a.end(),n) - a.begin();
        cout << min(abs(a[vt1] - n),abs(a[vt1-1] - n)) << '\n';
    }
    return 0;
}
