#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e7+1;
ll a[N];
map<ll,ll> f;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "FrequencyOfDigit"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll t;
    cin >> t;
    while(t--) {
        ll n,k;
        cin >> n >> k;
        for(int i = 1;i <= n;i++) {
            cin >> a[i];
            ll tmp = a[i];
            if(tmp == 0)f[0]++;
            while(tmp > 0) {
                ll ans = tmp % 10;
                f[ans]++;
                tmp /= 10;
            }
        }
        cout << f[k] << '\n';
        f.clear();
    }
    return 0;
}