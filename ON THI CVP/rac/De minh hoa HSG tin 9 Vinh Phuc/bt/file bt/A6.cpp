#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a,b,MOD;
ll dq(ll a,ll b)
{
    if(b == 0) return 0;
    ll x = dq(a,b/2);
    if(b % 2 == 1) return ((x+x) % MOD + a % MOD)%MOD;
    else return (x + x) % MOD;
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
    cin >> a >> b >> MOD;
    cout << dq(a,b);
    return 0;
}