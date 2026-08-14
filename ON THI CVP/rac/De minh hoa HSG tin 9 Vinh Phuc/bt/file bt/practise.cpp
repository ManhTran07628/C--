#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
ll a[N];
vector<pair<ll,ll>> vt;
int main()
{
    ll n,c;
    cin >> n >> c;
    for(int i = 0;i < n;i++) {
        ll a1,a2;
        cin >> a1 >> a2;
        vt.push_back({a1,a2});
    }
    sort(vt.begin(),vt.end());

    ll tong = 0;
    for(int i = 0;i < n;i++) {
        if(c >= vt[i].first) {
            tong++;
            c += vt[i].second;
        }
        else {
            break;
        }
    }
    cout << tong;
    return 0;
}
// 1 2 3 5 7
