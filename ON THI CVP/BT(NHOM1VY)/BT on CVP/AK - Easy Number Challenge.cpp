#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[N];
ll mod = 1073741824;
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
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            f[j]++;
        }
    }
    int a,b,c;
    cin >> a >> b >> c;
    ll ans = 0;
    for(ll i = 1;i <= a;i++)
        for(ll j = 1;j <= b;j++)
            for(ll k = 1;k <= c;k++) ans = (ans+f[i*j*k])%mod;
    cout << ans;
    return 0;
}