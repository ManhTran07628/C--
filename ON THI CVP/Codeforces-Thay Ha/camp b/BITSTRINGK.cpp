#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[N];
ll MOD = 1e9+7;
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
    f[0] = 1;
    f[1] = 2;
    for(int i = 2;i <= n;i++) {
        f[i] = f[i-1];
        if(i-k-1 > 0) f[i] += f[i-k-1];
        else f[i] += f[0];
        f[i] %= MOD;
    }
    cout << f[n];
    return 0;
}