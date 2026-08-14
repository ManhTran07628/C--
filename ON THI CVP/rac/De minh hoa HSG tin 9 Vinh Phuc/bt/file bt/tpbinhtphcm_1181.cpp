#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7;
ll a[N];
map<ll,vector<ll>> b;
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
    ll L,R;
    cin >> L >> R;
    for(int i = L;i <= R;i++) {
        ll ans = i,tong = 0;
        while(ans > 0) {
            ll tmp = ans % 10;
            tong += tmp;
            ans /= 10;
        }
        b[tong].push_back(i);
    }
    ll max1 = -1e9;
    for (auto &c : b) {
        if (!c.second.empty()) {
            ll vtd = c.second.front();
            ll vtc = c.second.back(); 
            max1 = max(max1, abs(vtd - vtc));
        }
    }

    cout << max1 << endl;
    return 0;
}