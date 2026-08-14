#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int SIZE = 2;
const int MM = 1e6+7;
ll a[SIZE + 5][SIZE + 5],f[MM],t;
map<ll,ll> mp;
ll MOD = -1;

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
    cin >> t;

    a[1][1] = a[1][2] = 1;
    a[2][1] = 1;
    f[1] = 1; f[2] = 1;
    while(t--) {
        ll n,j,k;
        cin >> n >> j >> k;
        MOD = k;
        Matrix I;
        if(j <= 2) {
            f[1] = f[2] = 1;
        }
        else {
            Matrix F1 = I ^ (j - 2);
            Matrix F2 = I ^ (j - 1);
            f[1] = (F1.x[1][1] + F1.x[1][2]) % MOD;
            f[2] = (F2.x[1][1] + F2.x[1][2]) % MOD ;
        }
        // cout << f[1] << ' ' << f[2] << ' ';
        for(int i = 3;i <= n;i++) {
            f[i] = (f[i-1] + f[i-2]) % MOD;
            // cout << f[i] << ' ';
        }




        ll sum = 0,st = -1,en = -1;
        for(int i = 1;i <= n;i++) {
            sum += f[i];
            sum %= MOD;
            if(sum == 0) {
                en = i;
                if(!mp[ sum ]) st = 1;
                else st = mp[ sum ];
                break;
            }

            if(!mp[ sum ]) mp[ sum ] = i;
            else {
                st = mp[ sum ] + 1;
                en = i;
                break;
            }
        }
        mp.clear();
        if(st == -1 && en == -1) cout << 0 << '\n';
        else {
            cout << en - st + 1 << ' ';
            for(int i = st;i <= en;i++) cout << i+j-1 << ' ';
            cout << '\n';
        }
    }
}



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
