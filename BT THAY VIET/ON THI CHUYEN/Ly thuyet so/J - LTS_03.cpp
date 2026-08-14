#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
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
    ll n,k;
    cin >> n >> k;
    for(ll i = 2;i*i <= n;i++) {
        while(n % i == 0) {
            n /= i;
            f.push_back(i);
        }
    }
    if(n > 1) f.push_back(n);
    if(f.size() < k) {
        cout << -1;
        return 0;
    }
    ll j = 1, ans = 1;
    for(auto i:f) {
        if(j < k) {
            cout << i << ' ';
            j++;
        }
        else {
            ans *= i;
        }
    }
    if(ans != 1) cout << ans << '\n';
    return 0;
}