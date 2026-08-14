#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e6+7;
const int SIZE = 3;
const int MOD = 1e9 + 7;
ll n,a[SIZE + 7][SIZE + 7];


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
                    c.x[i][j] = (c.x[i][j] + x[i][k] * b.x[k][j]) % (MOD-1);
                

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
    if(k == 0) return 1;
    ll c = binpow(a,k/2) % MOD;
    if(k % 2 == 1) return (c * c * a) % MOD;
    return (c * c) % MOD;
}

void solve()
{
    cin >> n;
    a[1][1] = a[1][2] = a[1][3] = 1;
    a[2][1] = 1;
    a[3][2] = 1;

    Matrix I;
    if(n <= 3) cout << n;
    else {
        Matrix A = I ^ (n - 3);
        // cout << binpow(3,A.x[1][1]) << '\n';
        cout << (  binpow(3, A.x[1][1]) * binpow(2, A.x[1][2]) * binpow(1, A.x[1][3])  ) % MOD;
        // cout << (A.x[1][1] * 3 * A.x[1][2] * 2 * A.x[1][3]) % MOD;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}