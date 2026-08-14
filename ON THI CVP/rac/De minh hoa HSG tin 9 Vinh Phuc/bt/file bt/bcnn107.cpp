#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[N];
ll MOD = 1e9 + 7;

ll lcm(ll a,ll b)
{
    return a / __gcd(a,b) * b;
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
    }
    ll crr = (a[1] / __gcd(a[1],a[2]) * a[2]) % MOD;
    for(int i = 2;i <= n;i++) {
        crr = lcm(crr,a[i]) % MOD;
    }
    cout << crr;
    return 0;
}