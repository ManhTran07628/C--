#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
vector<pair<ll,ll>> b;
int main()
{
    ll n,q;
    cin >> n >> q;
    for(int i = 0;i < n;i++) {
        ll a1,w1;
        cin >> a1 >> w1;
        b.push_back({w1,a1});
    }
    sort(b.begin(),b.end());
    for(int i = 0;i < n;i++) {
        a[i+1] = b[i].second;
        a[i+1] += a[i];
    }
    while(q--) {
        ll k;
        cin >> k;
        ll dau = 0,cuoi = n-1,vt = 0;
        while(dau <= cuoi) {
            ll mid = (dau + cuoi) / 2;
            if(a[mid] >= k) {
                vt 
            }
        }
        ll ans = lower_bound(a,a+n,k) - a;
        cout << b[ans-1].first << '\n';
    }
    return 0;
}
