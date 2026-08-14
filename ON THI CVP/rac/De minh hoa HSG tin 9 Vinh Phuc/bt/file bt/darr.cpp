#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+7;
vector<ll> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "darr"
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
        a.push_back(a1);
    }
    sort(a.begin(),a.end());
    ll max1 = 0;
    for(int i = 0;i < n;i++) {
        for(int j = a[i]*2;j <= a[i]+a[n-1];j+=a[i]) {
            auto vtd = lower_bound(a.begin(),a.end(),j);
            if(vtd != a.begin()) {
                max1 = max(max1,*--vtd%a[i]);
            }
        }
    }
    cout << max1;
    return 0;
}