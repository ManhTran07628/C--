#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;
vector<pair<ll,ll>> a;
int main() {
    ll n;
    cin >> n;
    ll max1 = -1e9,min1 = 1e9;
    while(n--) {
        ll v,d;
        cin >> v >> d;
        a.push_back({v-d,v+d});
    }
    sort(a.begin(),a.end());
    ll dau = a[0].first,cuoi = a[0].second;
    for(int i = 0;i < a.size();i++) {
        if(a[i].first > cuoi) {
            cout << -1;
            return 0;
        }
        cuoi = min(cuoi,a[i].second);
            
    }
    cout << cuoi;
    return 0;
}
// -1 3
//  1 5
//