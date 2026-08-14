#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 4;
int MOD = 1e9 + 7;
ll n,f[SIZE + (int) 1e7],a[SIZE + 7][SIZE + 7],g[SIZE + (int) 1e7];

struct Matrix
{
    ll x[SIZE + 7][SIZE + 7];

    Matrix() {

        for(int i = 1;i <= SIZE;i++) {
            for(int j = 1;j <= SIZE;j++) {
                x[i][j] = a[i][j];
            }
        }

    };

    Matrix operator * (Matrix const &b)
    {
        Matrix c;

        for(int i = 1;i <= SIZE;i++) {
            for(int j = 1;j <= SIZE;j++) {

                c.x[i][j] = 0;

                for(int k = 1;k <= SIZE;k++) {
                    c.x[i][j] = (c.x[i][j] + x[i][k] * b.x[k][j]) % MOD;
                }


            }
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

namespace brute
{
    void solve()
    {
        ll n;
        cin >> n;
        cout << g[n] << '\n';
    }
}

void solve()
{
    ll n;
    cin >> n;
    f[2] = 17; g[2] = 35;
    f[1] = 5; g[1] = 7;
    a[1][1] = 4; a[1][2] = 1; a[1][3] = 1; a[1][4] = 2;
    a[2][2] = 3; a[2][3] = 2;
    a[3][2] = 1;
    a[4][4] = 1;
    if(n <= 2) cout << g[n];
    else {
        Matrix I;
        Matrix A = I ^ (n - 2);
        cout << (A.x[1][1] * g[2] + A.x[1][2] * f[2] + A.x[1][3] * f[1] + A.x[1][4] * 1) % MOD;
    }
    cout << '\n';
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // f[2] = 5; g[2] = 35;
    // f[1] = 1; g[1] = 7;
    // for(int i = 3;i <= 1e7;i++) {
    //     f[i] = f[i-1] * 3 + f[i-2] * 2;
    //     f[i] %= MOD;
    //     g[i] = 4 * g[i-1] + f[i] + 2;
    //     g[i] %= MOD;
    // }
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}