#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a;
ll MOD = 123456789;

ll binpow(ll a,ll b)
{
    ll ans = 1;
    a %= MOD;
    while(b > 0) {
        if(b % 2 == 1) ans *= a % MOD;
        a *= a % MOD;
        b /= 2;
    }
    return ans;
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
    ll n,x;
    cin >> n >> x;
    x %= MOD;
    ll px = 0;
    for(int i = 1;i <= n+1;i++) {
        cin >> a;
        px = (px+a*binpow(x,i-1)+MOD) % MOD; 
        //cout << a*binpow(x,i-1) << ' ';
    }
    cout << (px+MOD) % MOD;
    return 0;
}