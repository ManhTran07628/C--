#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll n;
ll MOD = 1e9+7;
ll factoral(ll n)
{
    ll ans = 1;
    for(int i = 1;i <= n-4;i++) {
        ans = ans * i;
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
    ll n,ans = 0;
    cin >> n;
    ll x = factoral(n);
    //cout << x;
    if(n == 3) {
        cout << 0;
        return 0;
    }
    for(int a = 1;a <= n;a++) {
        for(int i = 1;i <= 9;i++) {
            for(int j = 0;j <= 9;j++) {
                for(int k = 0;k <= 9;k++) {
                    for(int h = 0;h <= 9;h++) {
                        ll m = i*1000+j*100+k*10+h;
                        if(m % 16 == 0
                            && i != j && i != k && i != h
                            && j != i && j != k && j != h
                            && k != i && k != j && k != h
                            && h != i && h != j && h != k
                        ) {
                            //cout << m << '\n';
                            ans = ans +  x % MOD;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}