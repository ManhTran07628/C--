#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 2;
ll MOD = 1e9+7;
ll n,f[SIZE + 7],a[SIZE + 7][SIZE + 7];

ll Indmul(ll a,ll b)
{
    if(b == 0) return 0;
    if(b == 1) return a;
    ll c = Indmul(a,b / 2);
    if(b % 2 == 1) return (c + c + a) % MOD;
    return (c + c) % MOD;
}

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
                    c.x[i][j] = (c.x[i][j] + Indmul(x[i][k], b.x[k][j]) ) % MOD;
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

void solve()
{
    ll n,A,B;
    cin >> A >> B >> MOD >> n;
    f[2] = A;
    f[1] = B;
    a[1][1] = A % MOD; a[1][2] = B % MOD;
    a[2][1] = 0; a[2][2] = 1;
    if(n <= 1) cout << f[n] % MOD;
    else {
        Matrix I;
        Matrix A = I ^ (n - 1);
        cout << (Indmul(A.x[1][1],B) + Indmul(A.x[1][2],1)) % MOD;

    }
    cout << '\n';
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
    // cout << Indmul(100,5);
    return 0;
}