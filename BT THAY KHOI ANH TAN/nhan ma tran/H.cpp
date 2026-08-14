#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 5;
const int MOD = 1e9+7;
ll n,a[SIZE + 7][SIZE + 7],f[SIZE + 7];


struct Matrix
{
    ll x[SIZE + 7][SIZE + 7];

    Matrix()
    {
        for(int i = 1;i <= SIZE;i++) 
            for(int j = 1;j <= SIZE;j++) 
                x[i][j] = a[i][j];
    }

    Matrix operator * (Matrix const &b)
    {
        Matrix c;
        for(int i = 1;i <= SIZE;i++)
            for(int j = 1;j <= SIZE;j++) {
                c.x[i][j] = 0;

                for(int k = 1;k <= SIZE;k++)
                    c.x[i][j] = (c.x[i][j] + x[i][k] * b.x[k][j]) % (MOD - 1);

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




ll binpow(ll x,ll k)
{
    ll ans = 1;
    while(k > 0) {
        if(k % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        k /= 2;
    }
    return ans;
}

void solve()
{
    cin >> n;
    f[4] = 2; f[5] = 6; f[6] = 14;

    a[1][1] = a[1][2] = a[1][3] = 1;
    a[2][1] = 1;
    a[3][2] = 1;

    Matrix I;

    a[1][1] = a[1][2] = a[1][3] = 1; a[1][4] = 2; a[1][5] = -4;
    a[2][1] = 1;
    a[3][2] = 1;
    a[4][4] = 1; a[4][5] = 1;
    a[5][5] = 1;

    Matrix T;

    if(n <= 3) cout << n;
    else {
        Matrix A = I ^ (n - 3);
        Matrix C;
        ll Ci = 0;
        if(n <= 6) Ci = f[n];
        else {
            C = T ^ (n - 6);
            Ci = (C.x[1][1] * f[6] + C.x[1][2] * f[5] + C.x[1][3] * f[4]) + C.x[1][4] * 6 + C.x[1][5] % MOD;
            // do minh bat dau so tai vi tri 7 nen khi do se phai * 6
            // 4 -> 2
            // 5 -> 4
            // 6 -> 6
            // 7 -> 8
        }

        cout << ( ( binpow(3,A.x[1][1])  * binpow(2,A.x[1][2]) ) % MOD * binpow(4,Ci) ) % MOD;

    }

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}