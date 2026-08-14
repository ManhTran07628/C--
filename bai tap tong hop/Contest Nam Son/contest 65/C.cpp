#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
vector<ll> a;
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
    ll m = 1;
    for(int i = 1;i <= n;i++) {
        ll b;
        cin >> b;
        a.push_back(b);
        m = max(m,b);
    }
    sort(a.begin(),a.end());
    ll ans = 0;
    for(ll i:a) {
        for(int j = i*2;j <= m*3;j+=i) {
            auto p = lower_bound(a.begin(),a.end(),j);
            if(p != a.begin()) {
                p--;
                ans = max(ans,*p % i);
            }
        }
    }
    cout << ans;//
    return 0;   
}