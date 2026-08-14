#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[1001][1001],a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll k,n;
    cin >> n >> k;
    for(int i = 1;i <= n;i++) cin >> a[i];
    ll MOD = 1e9+7;
    f[0][0] = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= k;j++) {
            f[i][j] = f[i-1][j] % MOD;
            if(j > 0) {
                f[i][j] = (f[i][j] + f[i-1][j-1] * a[i]) % MOD;
            }
        }
    }
    cout << f[n][k];
    return 0;
}