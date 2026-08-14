#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 500+7;
const int LOG = 10;
int n,m,q;
int a[MM][MM],st[MM][LOG + 2][MM][LOG + 2];

int get(int X1,int Y1,int X2,int Y2)
{
    int i = __lg(X2 - X1 + 1);
    int k = __lg(Y2 - Y1 + 1);
    return min({st[X1][i][Y1][k],
                st[X1][i][Y2 - (1 << k) + 1][k],
                st[X2 - (1 << i) + 1][i][Y1][k],
                st[X2 - (1 << i) + 1][i][Y2 - (1 << k) + 1][k]});
}

signed main()
{       
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {  
            cin >> a[i][j];
            // st[i][0][j][0] = a[i][j];
        }

    for(int j = 0;j <= LOG;j++)
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            
            for(int k = 0;k <= LOG;k++)
                for(int t = 1;t + (1 << k) - 1 <= m;t++) {

                    if(j == 0 && k == 0) st[i][j][t][k] = a[i][t];
                    if(j > 0 && k == 0) st[i][j][t][k] = min(st[i][j-1][t][k],
                                                            st[i + (1 << (j-1) )][j-1][t][k]);
                    if(j == 0 && k > 0)
                        st[i][j][t][k] = min(st[i][j][t][k-1],
                                            st[i][j][t + (1 << (k-1) )][k-1]);
                    if(j > 0 && k > 0)
                        st[i][j][t][k] = min(st[i][j-1][t][k],st[i + (1 << (j-1) )][j-1][t][k]);
                }

        }
    
    while(q--) {
        int X1,Y1,X2,Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << get(X1,Y1,X2,Y2) << '\n';
    }
    return 0;
}