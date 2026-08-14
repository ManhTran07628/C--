#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 100 + 7;
const int base1 = 256, base2 = 300;
const int MOD[] = {(ll) 1e9 + 2277,(ll) 1e9 + 5577};
int t,n,m;
ll Hash1[MM][MM],Hash2[MM][MM];
ll p1[MM][2],p2[MM][2];

ll get1(int X1,int Y1,int X2,int Y2)
{
    ll res = (Hash1[X2][Y2] - Hash1[X1 - 1][Y2] * p1[X2-X1+1][0] % MOD[0] - Hash1[X2][Y1 - 1] * p2[Y2-Y1+1][0] % MOD[0] + 
        Hash1[X1 - 1][Y1 - 1] * p1[X2-X1+1][0] % MOD[0] * p2[Y2-Y1+1][0] % MOD[0]);
    res = (res % MOD[0] + MOD[0]) % MOD[0];
    return res;
}

ll get2(int X1,int Y1,int X2,int Y2)
{
    ll res = (Hash2[X2][Y2] - Hash2[X1 - 1][Y2] * p1[X2-X1+1][1] % MOD[1] - Hash2[X2][Y1 - 1] * p2[Y2-Y1+1][1] % MOD[1] + 
        Hash2[X1 - 1][Y1 - 1] * p1[X2-X1+1][1] % MOD[1] * p2[Y2-Y1+1][1] % MOD[1]);
    res = (res % MOD[1] + MOD[1]) % MOD[1];
    return res;
}

// row - base[0]
// col - base[1]

void solve()
{
    cin >> n >> m;
    unordered_map<ll,ll> mp[10001];
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;
        s = ' ' + s;
        for(int j = 1;j <= m;j++) {
            Hash1[i][j] = (Hash1[i-1][j] * base1 % MOD[0] + Hash1[i][j-1] * base2 % MOD[0] 
                - Hash1[i-1][j-1] * base1 % MOD[0] * base2 % MOD[0] + s[j]) % MOD[0];

            Hash2[i][j] = (Hash2[i-1][j] * base1 % MOD[1] + Hash2[i][j-1] * base2 % MOD[1] 
                - Hash2[i-1][j-1] * base1 % MOD[1] * base2 % MOD[1] + s[j]) % MOD[1];

            Hash1[i][j] = (Hash1[i][j] + MOD[0]) % MOD[0];
            Hash2[i][j] = (Hash2[i][j] + MOD[1]) % MOD[1];
        }
    }



    for(int u = 1;u <= n;u++) 
        for(int v = 1;v <= m;v++) {
            for(int X1 = 1;X1 + u - 1 <= n;X1++) 
                for(int Y1 = 1;Y1 + v - 1 <= m;Y1++) {
                    int X2 = X1 + u - 1, Y2 = Y1 + v - 1;
                    ll h1 = get1(X1,Y1,X2,Y2), h2 = get2(X1,Y1,X2,Y2);
                    ll key = (1ll * h1 << 32) | h2;
                    mp[u * v][key] = 1;
                }
            
        } 
    
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;
        s = ' ' + s;
        for(int j = 1;j <= m;j++) {
            Hash1[i][j] = (Hash1[i-1][j] * base1 % MOD[0] + Hash1[i][j-1] * base2 % MOD[0] 
                - Hash1[i-1][j-1] * base1 % MOD[0] * base2 % MOD[0] + s[j]) % MOD[0];

            Hash2[i][j] = (Hash2[i-1][j] * base1 % MOD[1] + Hash2[i][j-1] * base2 % MOD[1] 
                - Hash2[i-1][j-1] * base1 % MOD[1] * base2 % MOD[1] + s[j]) % MOD[1];

            Hash1[i][j] = (Hash1[i][j] + MOD[0]) % MOD[0];
            Hash2[i][j] = (Hash2[i][j] + MOD[1]) % MOD[1];
        }
    }

    int res = 0;
    for(int u = 1;u <= n;u++) 
        for(int v = 1;v <= m;v++) {
            for(int X1 = 1;X1 + u - 1 <= n;X1++) 
                for(int Y1 = 1;Y1 + v - 1 <= m;Y1++) {
                    int X2 = X1 + u - 1, Y2 = Y1 + v - 1;
                    ll h1 = get1(X1,Y1,X2,Y2), h2 = get2(X1,Y1,X2,Y2);
                    ll key = (1ll * h1 << 32) | h2;
                    if(mp[u * v].find(key) != mp[u * v].end()) res = max(res,u * v);
                }
            
        }
    cout << res << '\n';
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    p1[0][0] = p1[0][1] = p2[0][0] = p2[0][1] = 1;
    for(int i = 1;i < MM;i++) {
        p1[i][0] = (p1[i-1][0] * base1) % MOD[0];
        p1[i][1] = (p1[i-1][1] * base1) % MOD[1];
        
        p2[i][0] = (p2[i-1][0] * base2) % MOD[0];
        p2[i][1] = (p2[i-1][1] * base2) % MOD[1];
    }
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}