#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
vector<ll> f;
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
    ll n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) f.push_back(a[i]);
    }
    sort(f.begin(),f.end());
    while(q--) {
        ll x;
        cin >> x;
        ll tpos = lower_bound(f.begin(),f.end(),x) - f.begin();
        if(f[tpos] == x) cout << tpos+1 << '\n';
        else if(f[tpos] > x) cout << tpos << '\n';
    }
    return 0;
}