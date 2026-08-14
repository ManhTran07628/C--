#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 2;
ll n;
double p,a[SIZE + 7][SIZE + 7];

struct Matrix
{
    double x[SIZE + 7][SIZE + 7];

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
                    c.x[i][j] = (c.x[i][j] + x[i][k] * b.x[k][j]);
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
};

void solve()
{
    cin >> n >> p;
    a[1][1] = 1-p; a[1][2] = p;
    a[2][1] = p; a[2][2] = 1-p;

    Matrix I;
    if(n == 1) cout << fixed << setprecision(6) << 1-p;
    else {
        Matrix A = I ^ (n-1);
        double ans = A.x[1][1] * (1-p) + A.x[1][2] * p;
        cout << fixed << setprecision(6) << ans;
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}