#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
vector<ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "tomau"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    f.push_back(a[1]);
    for(int i = 2;i <= n;i++) {
        ll vtd = lower_bound(f.begin(),f.end(),a[i]) - f.begin();
        if(vtd == f.size()) {
            f.push_back(a[i]);
        }
        else {
            f[vtd] = a[i];
        }
    }
    cout << f.size();
    return 0;
}