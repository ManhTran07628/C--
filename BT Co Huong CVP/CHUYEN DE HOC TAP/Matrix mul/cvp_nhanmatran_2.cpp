#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int SIZE = 2;
const int MOD = 1e9 + 7;
ll a[SIZE + 5][SIZE + 5],f[SIZE + 5];

struct Matrix
{
    ll x[SIZE + 5][SIZE + 5];

    Matrix()
    {
        for(int i = 1;i <= SIZE;i++)
            for(int j = 1;j <= SIZE;j++) 
                x[i][j] = a[i][j];
    }

    Matrix operator * (const Matrix &b)
    {
        Matrix c;
        for(int i = 1;i <= SIZE;i++)
            for(int j = 1;j <= SIZE;j++) {
                c.x[i][j] = 0;
                for(int k = 1;k <= SIZE;k++) {
                    c.x[i][j] = (c.x[i][j] + x[i][k] * b.x[k][j]) % MOD;
                }
            }

        return c;
    }

    friend Matrix operator ^ (Matrix &a,ll k)
    {
        if(k == 1) return a;
        Matrix c = a ^ (k / 2);
        if(k % 2 == 1) return c * c * a;
        return c * c;
    }
};

void solve()
{
    ll n;
    cin >> n;
    a[1][1] = 1; a[1][2] = 2;
    a[2][1] = 1; a[2][2] = 0;
    f[2] = 3;
    f[1] = 1;
    if(n <= 2) cout << f[n] << '\n';
    else {
        Matrix I;
        Matrix A = I ^ (n - 2);
        cout << (A.x[1][1] * f[2] + A.x[1][2] * f[1]) % MOD << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}