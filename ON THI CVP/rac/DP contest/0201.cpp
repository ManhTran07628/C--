#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
vector<ll> v;
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
    ll t;
    int i = 1;
    while(cin >> t) {
        a[i] = t;
        i++;
    }
    i--;ll n = i;
    reverse(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        ll rb = upper_bound(v.begin(),v.end(),a[i]) - v.begin();
        if(rb == v.size()) {
            v.push_back(a[i]);
        }
        else v[rb] = a[i];
    }
    cout << v.size() << '\n';
    v.clear();
    reverse(a+1,a+n+1);
    for(int i = 1;i <= n;i++) {
        ll rb = lower_bound(v.begin(),v.end(),a[i]) - v.begin();
        if(rb == v.size()) {
            v.push_back(a[i]);
        }
        else v[rb] = a[i];
    }
    cout << v.size();
    return 0;
}