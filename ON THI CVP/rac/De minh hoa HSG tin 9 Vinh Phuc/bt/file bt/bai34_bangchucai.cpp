#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1001;
ll a[N];
vector<ll> b;
int main()
{
    freopen("alpha.inp","r",stdin);
    freopen("alpha.out","w",stdout);
    ll t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        ll dem = 0;
        for(ll i = 0;i < s.size();i++) {
            dem = max(dem,(ll)(s[i] - 96));
        }
        cout << dem << endl;
    }
    return 0;
}


