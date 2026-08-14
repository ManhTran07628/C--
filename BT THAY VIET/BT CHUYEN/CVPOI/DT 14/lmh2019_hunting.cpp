#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 100 + 7;
int n,m,a[MM][MM],dp[MM][MM][MM];
int trace1[MM][MM][MM],trace2[MM][MM][MM];
int Move[] = {-1,0,1};
char T[] = {'L','D','R'};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }

    memset(dp,-1,sizeof(dp));
    int c = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= m;j++) {
            if(i == j) {
                c = a[1][j];
            }
            else c = a[1][i] + a[1][j];

            dp[1][i][j] = c;
        }
    }

    for(int i = 2;i <= n;i++) {
        int c = 0;
        for(int u = 1;u <= m;u++) {
            for(int v = 1;v <= m;v++) {

                if(u == v) c = a[i][u];
                else c = a[i][u] + a[i][v];

                for(int x = 0;x < 3;x++)
                    for(int y = 0;y < 3;y++) {
                        int last_x = Move[x] + u, last_y = Move[y] + v;
                        
                        if(dp[i - 1][last_x][last_y] == -1) continue;

                        if(dp[i][u][v] < dp[i - 1][last_x][last_y] + c) {
                            dp[i][u][v] = dp[i - 1][last_x][last_y] + c;
                            trace1[i][u][v] = last_x;
                            trace2[i][u][v] = last_y;
                        }

                    }
                
            }
        }
    }

    int res = 0;
    int x = 0,y = 0;
    for(int u = 1;u <= m;u++) 
        for(int v = 1;v <= m;v++) {
            if(res < dp[n][u][v]) {
                x = u, y = v;
                res = max(res,dp[n][u][v]);
            }
        }

    string move1,move2;

    int i = n;

    while(i != 1) {
        int last1 = trace1[i][x][y];
        int cur1 = x;

        int last2 = trace2[i][x][y];
        int cur2 = y;

        if(last1 - 1 == cur1 && dp[i]) move1.push_back('L');
        else if(last1 == cur1) move1.push_back('D');
        else if(last1 + 1 == cur1) move1.push_back('R');

        if(last2 - 1 == cur2) move2.push_back('L');
        else if(last2 == cur2) move2.push_back('D');
        else if(last2 + 1 == cur2) move2.push_back('R');


        x = last1;
        y = last2;
        i--;
    }
    reverse(move1.begin(),move1.end());
    reverse(move2.begin(),move2.end());
    cout << res << '\n' << x << ' ' << y << '\n' << move1 << '\n' << move2;

    return 0;
}