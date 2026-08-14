#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll h[N];
multiset<ll> ms;

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
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
        ms.insert(h[i]);
    }
    while(m--) {
        ll t;
        cin >> t;
        auto it = ms.upper_bound(t);
        if(it == ms.begin()) cout << -1 << '\n';
        else {
            --it;
            cout << *it << '\n';
            ms.erase(it);
        }
        
    }
    return 0;
}