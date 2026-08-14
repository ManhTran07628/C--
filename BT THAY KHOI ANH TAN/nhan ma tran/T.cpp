#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 64;
const ll MOD = 4294967296;
ll a[SIZE + 5][SIZE + 5],id[SIZE + 5][SIZE + 5],k;

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

bool check(int X,int Y)
{
    return (1 <= X && X <= 8 && 1 <= Y && Y <= 8);
}

void solve()
{
    cin >> k;
    int cnt = 0;
    for(int i = 1;i <= 8;i++)
        for(int j = 1;j <= 8;j++) {
            id[i][j] = ++cnt;
        }
    
    for(int X = 1;X <= 8;X++) {
        for(int Y = 1;Y <= 8;Y++) {
            if(check(X-2,Y+1)) a[ id[X-2][Y+1] ][ id[X][Y] ] = 1;
            if(check(X-1,Y+2)) a[ id[X-1][Y+2] ][ id[X][Y] ] = 1;
            if(check(X+1,Y+2)) a[ id[X+1][Y+2] ][ id[X][Y] ] = 1;
            if(check(X+2,Y+1)) a[ id[X+2][Y+1] ][ id[X][Y] ] = 1;
            if(check(X+2,Y-1)) a[ id[X+2][Y-1] ][ id[X][Y] ] = 1;
            if(check(X+1,Y-2)) a[ id[X+1][Y-2] ][ id[X][Y] ] = 1;
            if(check(X-1,Y-1)) a[ id[X-1][Y-1] ][ id[X][Y] ] = 1;
            if(check(X-2,Y-1)) a[ id[X-2][Y-1] ][ id[X][Y] ] = 1;
        }
    }

    if(k == 1) cout << 3;
    else {
        Matrix I;
        Matrix A = I ^ (k-1);
        // for(int i = 1;i <= 64;i++) {
        //     for(int j = 1;j <= 64;j++) {
        //         cout << a[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }


        ll ans = 0;
        for(int i = 1;i <= 64;i++)
            for(int j = 1;j <= 64;j++)
                ans = (ans + A.x[i][j]) % MOD;
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}