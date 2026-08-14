#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[N];
map<ll,ll> b;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "SALES"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n;
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll ans = 0;
    for(auto c:b) {
        ll cnt1 = c.second,cnt2 = 1e9;
        for(int i = 0;i <= (cnt1+1)/2;i++) {
            if((cnt1 - (i*2)) % 3 == 0) {
                cnt2 = min(cnt2,i+(cnt1 - (i*2))/3);
            }
        }
        if(cnt2 == 1e9) {
            cout << -1;
            return 0;
        }
        ans += cnt2;
    }
    cout << ans;
    return 0;
}