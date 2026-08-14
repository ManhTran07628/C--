#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
ll a[MAXN],b[MAXN],c[MAXN];
bool check(ll x,ll n,ll k)
{
    ll cntvo = 0;
    for(int i = 1;i <= n;i++) {
        if(c[i] > x) {
            ll val = (c[i]-x)/b[i];
            if((c[i]-x) % b[i] != 0) val++;
            cntvo += val;
        }
        if(cntvo > k) return 0;
    }
    if(cntvo <= k) return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    ll n,k;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) 
        cin >> a[i];
    for(int i = 1;i <= n;i++) {
        cin >> b[i];
        c[i] = a[i]*b[i];

    }
    ll l = 1,r = 1e18,ans = 1e18;
    while(l <= r) {
        ll mid = (l+r)/2;
        if(check(mid,n,k)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;   
}