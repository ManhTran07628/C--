#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int SIZE = 6;
const int MOD = 1e9+7;
ll a[SIZE + 5][SIZE + 5],n,f[SIZE + 5];


struct Matrix
{
    ll x[SIZE + 5][SIZE + 5];

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

ll binpow(ll a,ll k)
{
    ll ans = 1;
    while(k > 0) {
        if(k % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        k /= 2;
    }
    return ans;
}

void solve()
{
    cin >> n;
    a[1][1] = a[1][2] = a[1][3] = a[1][5] = 1; a[1][4] = 2;
    a[2][1] = 1;
    a[3][2] = 1;
    a[4][4] = 1;
    a[5][4] = 2; a[5][5] = 1;
    a[6][1] = a[6][2] = a[6][3] = a[6][5] = a[6][6] = 1; a[6][4] = 2;

    f[1] = 1; f[2] = 2; f[3] = 6;
    if(n <= 3) cout << f[n];
    else {
        Matrix I;
        Matrix A = I ^ (n - 3);
        cout << ( binpow(3,A.x[6][1]) % MOD * binpow(2,A.x[6][2]) % MOD *
                  binpow(4,A.x[6][4]) % MOD * binpow(6,A.x[6][6]) ) % MOD;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
