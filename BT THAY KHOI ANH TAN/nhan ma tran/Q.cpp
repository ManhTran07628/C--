#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int SIZE = 100;
const int MOD = 1e9+7;
int n,m,adj[SIZE + 7][SIZE + 7];
ll k;


void init()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++) {
        int u,v;
        cin >> u >> v;
        adj[v][u] = 1;
    }
}

struct Matrix
{
    ll x[SIZE + 5][SIZE + 5];
    Matrix()
    {
        for(int i = 1;i <= SIZE;i++)
            for(int j = 1;j <= SIZE;j++)
                x[i][j] = adj[i][j];
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
    init();
    // for(int i = 1;i <= n;i++) {
    //     for(int j = 1;j <= n;j++) {
    //         cout << adj[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    if(k == 1) cout << m;
    else {
        Matrix I;
        Matrix A = I ^ (k);


        // for(int i = 1;i <= n;i++) {
        //     for(int j = 1;j <= n;j++) {
        //         cout << A.x[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            
            for(int j = 1;j <= n;j++) {
                ans = (ans + A.x[i][j]) % MOD;

            }
        }
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