#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N],b[N],c[N];
ll MOD = 1e9 + 7;

ll scs(ll k)
{
    ll cnt = 0;
    while(k > 0) {
        cnt++;
        k /= 10;
    }
    return cnt;
}

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
        b[i] = b[i-1] + a[i];
        c[i] = c[i-1] + pow(10,scs(a[i]));
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = (ans + (b[i-1]%MOD)+(b[n]-b[i])%MOD+a[i]*(c[i-1])%MOD+a[i]*(c[n]-c[i])%MOD)%MOD;
    }
    cout << ans;
    return 0;
}