#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MOD = 1e9+7;
const int SIZE = 100;
int n;
ll t[SIZE + 7][SIZE + 7],a[SIZE + 7],c[SIZE + 7],p,K;


void init()
{
    cin >> n >> K;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    cin >> p;
}   

struct Matrix
{
    ll x[SIZE + 7][SIZE + 7];

    Matrix()
    {
        for(int i = 1;i <= SIZE;i++) 
            for(int j = 1;j <= SIZE;j++) {
                x[i][j] = t[i][j];
            }
        
    };

    Matrix operator * (Matrix const &b)
    {
        Matrix c;
        for(int i = 1;i <= SIZE;i++) 
            for(int j = 1;j <= SIZE;j++) {

                c.x[i][j] = 0;

                for(int k = 1;k <= SIZE;k++) 
                    c.x[i][j] = (c.x[i][j] + x[i][k] * b.x[k][j]) % MOD;

            }
        
        return c;
    }


    friend Matrix operator ^ (Matrix const &a,ll k)
    {
        if(k == 1) return a;
        Matrix c = a ^ (k / 2);

        if(k % 2 == 1) return c * c * a;
        return c * c;
    }

};


void solve()
{
    for(int i = 1;i <= n;i++) t[1][i] = c[i];
    t[1][n + 1] = 1;
    for(int i = 2;i <= n;i++) t[i][i-1] = 1;
    t[n+1][n+1] = 1;
    Matrix I;
    if(K <= n-1) cout << a[K];
    else {
        Matrix A = I ^ (K - n + 1);
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            ans = (ans + A.x[1][i] * a[n-i]) % MOD;
        }
        ans += (A.x[1][n+1] * p) % MOD;
        cout << ans;
    }
}




signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    solve();
    return 0;
}