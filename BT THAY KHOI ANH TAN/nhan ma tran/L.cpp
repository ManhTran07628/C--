#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int SIZE = 2;
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
    cin >> n;
    a[1][1] = 19; a[1][2] = 6;
    a[2][1] = 7; a[2][2] = 20;
    if(n == 1) cout << 19;
    else {
        Matrix I;
        Matrix A = I ^ (n-1);
        cout << (A.x[1][1] * 19 + A.x[1][2] * 7) % MOD;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
