#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 100;
const int MOD = 1e9+7;
ll n,k,a[SIZE + 7],c[SIZE + 7],p,q,r,S[SIZE + 7][SIZE + 7];

void init()
{
    cin >> n >> k;
    for(int i = 0;i < n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> c[i];
    cin >> p >> q >> r;
}

struct Matrix
{
    ll x[SIZE + 7][SIZE + 7];

    Matrix()
    {
        for(int i = 1;i <= SIZE;i++)    
            for(int j = 1;j <= SIZE;j++)
                x[i][j] = S[i][j];
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
        Matrix C = a ^ (k / 2);

        if(k % 2 == 1) return C * C * a;
        return C * C;
    }
}

void solve()
{
    for(int i = 0;i < n;i++) 
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}