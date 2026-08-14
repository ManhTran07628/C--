#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 1e3+7;
const int MS = 1e6 + 7;
const int MOD = 1e9 + 2277;
const int base = 256;
int n,m,p,q,a[MM][MM][51],val[MM][MM];
vector<int> v;
int mp[MS];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for(int t = 1;t <= p;t++) {
        int i,j,x,y,c;
        cin >> i >> j >> x >> y >> c;
        a[i][j][c]++;
        a[x+1][j][c]--;
        a[i][y+1][c]--;
        a[x+1][y+1][c]++;
    }

    for(int c = 1;c <= m;c++) 
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                a[i][j][c] += a[i-1][j][c] + a[i][j-1][c] - a[i-1][j-1][c];
            }
        }

    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++) {

            ll Hash = 0;
            for(int c = 1;c <= m;c++) {
                Hash = (Hash * base + a[i][j][c] + 1) % MOD;
            }
            val[i][j] = Hash;

            v.push_back(Hash);

        }
    cin >> q;
    while(q--) {
        int u,v;
        cin >> u >> v;

        cout << mp[ val[u][v] ] << '\n';
        // ll Hash = 0;
        // for(int c = 1;c <= m;c++) {
        //     Hash = (Hash * base + a[u][v][c] + 1) % MOD;
        // }

        // cout << mp[Hash] << '\n';
    }
    return 0;
}