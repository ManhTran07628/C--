#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 1;
vector<pair<ll,ll>> a;
ll b[N];
int main()
{
    #define taskname "CHISO"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        ll a1;
        cin >> a1;
        b[i] = a1;
        a.push_back({a1,(i+1)});
    }
    ll max1 = -1e9;
    sort(a.begin(),a.end());
    for(int i = 0;i < n;i++) {
        ll L = 0,R = n-1,vtd = -1;
        while(L <= R) {
            ll mid = (L+R)/2;
            if(a[mid].second > b[i]) {
                vtd = mid;
                R = mid - 1;
            }
            else {
                L = mid + 1;
            }
        }
        for(ll j = vtd;j < n;j++) {
            max1 = max(max1,j-i);
        }
    }
    cout << max1;
    return 0;
}
// 5
// 1 3 5 4 2
