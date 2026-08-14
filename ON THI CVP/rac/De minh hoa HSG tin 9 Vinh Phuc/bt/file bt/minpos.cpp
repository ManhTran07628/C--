#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;

vector<pair<ll,ll>> a;

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
        ll a1;
        cin >> a1;
        a.push_back({a1,i});
    }
    sort(a.begin(),a.end());
    ll q;
    cin >> q;
    while(q--) {
        ll k;
        cin >> k;
        ll L = 0,R = n-1,vt = -1;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(a[mid].first <= k) {
                vt = a[mid].second;
                R = mid - 1;
            }
            else L = mid + 1;
        }
        cout << vt << '\n';
    }
    return 0;
}