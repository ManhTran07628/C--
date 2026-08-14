#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 3e5 + 7;
const int MOD = 1e9 + 7;
const int lim = 1000;
int numCol, numRow, k, nvalid[1005][1005];
ll finv[MM], frac[MM], dp[1005][1005];

ll binpow(ll a,ll b)
{
    ll res = 1;
    while(b > 0) {
        if(b % 2) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}

void build()
{
    frac[0] = 1;
    for(int i = 1;i < MM;i++) frac[i] = frac[i-1] * 1ll * i % MOD;
    finv[MM - 1] = binpow(frac[MM - 1],MOD - 2);
    for(int i = MM - 1;i >= 1;i--)
        finv[i - 1] = 1ll * finv[i] * i % MOD;
}

ll getpath(int X1,int Y1,int X2,int Y2)
{
    int K = (X2 - X1), N = (X2 - X1) + (Y2 - Y1);
    return frac[N] * finv[N - K] % MOD * finv[K] % MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    build();
    int maxBlockRow = 1, maxBlockCol = 1;
    // cin >> numRow >> numCol >> k;
    for(int i = 1;i <= k;i++) {
        int x,y; cin >> x >> y;
        nvalid[x][y] = 1;
        maxBlockRow = max(maxBlockRow,x);
        maxBlockCol = max(maxBlockCol,y);
    }

    dp[1][1] = 1;
    for(int i = 1;i <= maxBlockRow;i++)
        for(int j = 1;j <= maxBlockCol;j++) {
            if(nvalid[i][j]) continue;
            dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    
    if(numRow == maxBlockRow && numCol == maxBlockCol) {
        cout << dp[numRow][numCol];
        return 0;
    }

    ll res = 0;
    if(maxBlockRow < numRow) {
        for(int i = 1;i <= maxBlockCol;i++) {
            int X1 = maxBlockRow + 1, Y1 = i;
            int X2 = numRow, Y2 = numCol;
            res = (res + dp[maxBlockRow][i] % MOD * getpath(X1,Y1,X2,Y2) % MOD) % MOD;
        }
    }
    
    if(maxBlockCol < numCol) {
        for(int i = 1;i <= maxBlockRow;i++) {
            int X1 = i, Y1 = maxBlockCol + 1;
            int X2 = numRow, Y2 = numCol;
            res = (res + dp[i][maxBlockCol] % MOD * getpath(X1,Y1,X2,Y2) % MOD) % MOD;
        }
    }
    // cout << res % MOD;
    cout << frac[2] * finv[0] % MOD * finv[2] % MOD;
    return 0;
}