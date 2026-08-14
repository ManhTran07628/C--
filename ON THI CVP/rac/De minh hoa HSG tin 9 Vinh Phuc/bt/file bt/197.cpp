#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        f.push_back(a[i]);
    }
    sort(f.begin(),f.end());
    f.erase(unique(f.begin(),f.end()),f.end());
    ll ans = 0;
    for(ll i:f) {
        ll fi = lower_bound(f.begin(),f.end(),i) - f.begin();
        ll se = upper_bound(f.begin(),f.end(),i+n-1) - f.begin();
        ans = max(ans,se-fi);
        //cout << fi << " " << se << '\n';
    }
    cout << n-ans;
    return 0;
}