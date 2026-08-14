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
    #define taskname "h9ndbd"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    ll ans = 0,cnt = 0;
    for(auto c:b) {
        if(c.second >= k) {
            ans++;
            cnt += c.first;
        }
    }
    cout << ans << " " << cnt;
    return 0;
}