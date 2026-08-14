#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7 + 7;
vector<pair<ll,ll>> a;

int main()
{
    ll m,n;
    cin >> m >> n;
    for(int i = 0;i < m;i++) {
        ll a1,a2;
        cin >> a1 >> a2;
        a.push_back({a1,a2});
    }
    sort(a.begin(),a.end(),greater<pair<ll,ll>>());
    cout << a[n-1].first << " " << a[n-1].second;
    return 0;
}
