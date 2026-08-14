#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 400 + 7;
int row_sz,col_sz,K,a[MM][MM];
const int SZ = 1e6 + 7;
ll mp[SZ];

int getsum(int x,int y,int u,int v,int k)
{
    return ((a[u][v] - a[u][y - 1] - a[x - 1][v] + a[x - 1][y - 1]) % k + k) % k;
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
    cin >> row_sz >> col_sz >> K;
    for(int i = 1;i <= row_sz;i++)
        for(int j = 1;j <= col_sz;j++) {
            cin >> a[i][j];
            a[i][j] = (a[i][j] % K + K) % K;
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            a[i][j] %= K;
        }

    ll res = 0;

    for(int i = 1;i <= row_sz;i++) {
        for(int j = i;j <= row_sz;j++) {
            
            mp[0] = 1;
            for(int k = 1;k <= col_sz;k++) {
                res += mp[ getsum(i,1,j,k,K) ];
                mp[ getsum(i,1,j,k,K) ]++;
            }
            for(int k = 1;k <= col_sz;k++) {
                mp[ getsum(i,1,j,k,K) ] = 0;
            }

        }
    }
    cout << res;
    return 0;
}