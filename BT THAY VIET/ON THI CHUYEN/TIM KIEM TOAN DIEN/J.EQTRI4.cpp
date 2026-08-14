#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN];
map<ll,ll> lt;
ll M = 1e9+7; 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1;i <= n;i++) {
        cin >> a[i];
        lt[a[i]]++;
    }
    ll ans = 0;   
    for(int i = 1;i <= 5000;i++) {
        ll p = lt[i]*(lt[i]-1)/2;
        ll p1 = lt[i-1]*(lt[i-1]-1)/2;
        ll t = p1*p;
        ans = (ans%M+t%M)%M;
    }
    cout << ans;
    return 0;
}