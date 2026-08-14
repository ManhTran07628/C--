#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 2e3+7;
int n,m,k,x[MM][MM],ans = 0,s[MM][MM],P[MM][MM];

void init()
{
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> x[i][j];
            P[i][j] = P[i-1][j] + P[i][j-1] + x[i][j] - P[i-1][j-1];
        }
    }
}

namespace subtask1
{
    int get_sum(int X1,int Y1,int X2,int Y2)
    {
        return P[X2][Y2] - P[X2][Y1-1] - P[X1-1][Y2] + P[X1-1][Y1-1];
    }

    bool check(int X1,int Y1,int X2,int Y2,int X3,int Y3,int X4,int Y4) 
    {
        if(X2 < X3) return 1; 
        if(X4 < X1) return 1; 
        if(Y2 < Y3) return 1;
        if(Y4 < Y1) return 1;
        return 0; 
    }


    void solve()
    {
        for(int X1 = 1;X1 <= n;X1++) {
            int X2 = X1+k-1;
            if(X2 > n) break;
            for(int Y1 = 1;Y1 <= m;Y1++) {
                int Y2 = Y1+k-1;
                if(Y2 > m) break;

                int sum1 = get_sum(X1,Y1,X2,Y2);

                for(int X3 = 1;X3 <= n;X3++) {
                    int X4 = X3+k-1;
                    if(X4 > n) break;
                    for(int Y3 = 1;Y3 <= m;Y3++) {
                        int Y4 = Y3+k-1;
                        if(Y4 > m) break;

                        if(!check(X1,Y1,X2,Y2,X3,Y3,X4,Y4)) continue;

                        int sum2 = get_sum(X3,Y3,X4,Y4);

                        for(int X5 = 1;X5 <= n;X5++) {
                            int X6 = X5+k-1;
                            if(X6 > n) break;
                            for(int Y5 = 1;Y5 <= m;Y5++) {
                                int Y6 = Y5+k-1;
                                if(Y6 > m) break;

                                if(!check(X1,Y1,X2,Y2,X5,Y5,X6,Y6) || !check(X3,Y3,X4,Y4,X5,Y5,X6,Y6)) continue;

                                int sum3 = get_sum(X5,Y5,X6,Y6);

                                if(sum1 + sum2 + sum3 > ans) {
                                    ans = max(ans,sum1+sum2+sum3);
                                }
                                
                            }
                        }


                    }
                }

            }


        }
        cout << ans;
    }
}


namespace subtask2
{
    int a[MM][MM],b[MM][MM],c[MM][MM],d[MM][MM],s[MM][MM];
    
    int get_sum(int X1,int Y1,int X2,int Y2)
    {
        return P[X2][Y2] - P[X2][Y1-1] - P[X1-1][Y2] + P[X1-1][Y1-1];
    }

    void process()
    {
        for(int i = k;i <= n;i++) {
            for(int j = k;j <= m;j++) {
                s[i][j] = get_sum(i-k+1,j-k+1,i,j);
            }
        }
        for(int i = k;i <= n;i++) {
            for(int j = k;j <= m;j++) {
                a[i][j] = max({s[i][j], a[i-1][j], a[i][j-1]});
            }
        }
        for(int i = k;i <= n;i++) {
            for(int j = m-k+1;j >= 1;j--) {
                b[i][j] = max({s[i][j+k-1], b[i-1][j], b[i][j+1]});
            }
        }
        for(int i = n-k+1;i >= 1;i--) {
            for(int j = k;j <= m;j++) {
                c[i][j] = max({s[i+k-1][j], c[i+1][j], c[i][j-1]});
            }
        }
        for(int i = n-k+1;i >= 1;i--) {
            for(int j = m-k+1;j >= 1;j--) {
                d[i][j] = max({s[i+k-1][j+k-1], d[i+1][j], d[i][j+1]});
            }
        }
        

        for(int i = k;i <= n;i++) {
            for(int j = k;j <= m;j++) {
                ans = max(ans, a[i-k][m] + s[i][j] + c[i+1][m]); 
                ans = max(ans, a[n][j-k] + s[i][j] + b[n][j+1]);
            }
        }

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                ans = max(ans, a[i][j] + b[i][j+1] + c[i+1][m]);
                ans = max(ans, a[i][m] + c[i][j] + d[i+1][j+1]);
                ans = max(ans, a[i][j] + b[n][j+1] + c[i+1][j]); 
                ans = max(ans, a[n][j] + b[i][j+1] + d[i+1][j+1]); 
            }
        }
        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    subtask2::process();
    return 0;   
}