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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a+1,a+n+1);
    for(int i = 2;i <= n;i++) {
        a[i].se = min(a[i].se,a[i-1].se);
    }
    ll q;
    cin >> q;
    while(q--) {
        ll x;
        cin >> x;
        auto it = lower_bound(a+1,a+n+1,make_pair(x,-1ll));
        cout << it->se << '\n';
    }
    return 0;
}