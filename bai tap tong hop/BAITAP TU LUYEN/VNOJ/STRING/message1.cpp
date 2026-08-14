#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 100 + 7;
const int base1 = 256;
const int base2 = 300;
const int MOD = 1e9 + 2277;
ll Hash[MM][MM],powR[MM],powC[MM],Row[MM][MM];
char a[MM][MM];
map<ll,ll> mp;

ll getHash(int X1,int Y1,int X2,int Y2) {
    ll res = Hash[X2][Y2];
    res = (res - Hash[X1 - 1][Y2] * powR[X2 - X1 + 1] % MOD + MOD) % MOD;
    res = (res - Hash[X2][Y1 - 1] * powC[Y2 - Y1 + 1] % MOD + MOD) % MOD;
    res = (res + Hash[X1 - 1][Y1 - 1] * powR[X2 - X1 + 1] % MOD * powC[Y2 - Y1 + 1] % MOD) % MOD;
    return res;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            Row[i][j] = (Row[i][j-1] * base1 + a[i][j] - '0' + 1) % MOD;
        }

    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            Hash[i][j] = (Hash[i-1][j] * base2 + Row[i][j]) % MOD;
        }

    for(int len1 = 1;len1 <= n;len1++) {
        for(int len2 = 1;len2 <= m;len2++) {

            for(int X1 = 1;X1 + len1 - 1 <= n;X1++)
                for(int Y1 = 1;Y1 + len2 - 1 <= m;Y1++) {

                    int X2 = X1 + len1 - 1;
                    int Y2 = Y1 + len2 - 1;

                    mp[ getHash(X1,Y1,X2,Y2) ] = 1;

                }

        }
    }

    memset(Hash,0,sizeof(Hash));
    memset(Row,0,sizeof(Row));

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            Row[i][j] = (Row[i][j-1] * base1 + a[i][j] - '0' + 1) % MOD;
            cout << a[i][j];
        }
        cout << '\n';
    }

    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            Hash[i][j] = (Hash[i-1][j] * base2 + Row[i][j]) % MOD;
        }

    int res = 0;
    for(int len1 = 1;len1 <= n;len1++) {
        for(int len2 = 1;len2 <= m;len2++) {

            for(int X1 = 1;X1 + len1 - 1 <= n;X1++)
                for(int Y1 = 1;Y1 + len2 - 1 <= m;Y1++) {

                    int X2 = X1 + len1 - 1;
                    int Y2 = Y1 + len2 - 1;

                    if(mp[ getHash(X1,Y1,X2,Y2) ]) {
                        res = max(res,(X2 - X1 + 1) * (Y2 - Y1 + 1));
                    }

                }

        }
    }

    memset(Hash,0,sizeof(Hash));
    memset(Row,0,sizeof(Row));
    mp.clear();

    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    powR[0] = 1;
    powC[0] = 1;

    for(int i = 1;i < MM;i++) powC[i] = (powC[i-1] * base1) % MOD;
    for(int i = 1;i < MM;i++) powR[i] = (powR[i-1] * base2) % MOD;

    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}