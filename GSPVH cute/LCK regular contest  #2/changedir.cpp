#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2207 + 7;
const int MOD = 998244353;
int dp[MM][MM][6],f[MM][MM];
char a[MM][MM];
vector<int> dx{0,1,1,1,2};
vector<int> dy{1,0,2,1,1};
int row,col;

struct Node{int x,y,state;};

bool valid(int x,int y)
{
    return (1 <= x && x <= row && 1 <= y && y <= col);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "changedir"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> row >> col;
    for(int i = 1;i <= row;i++)
        for(int j = 1;j <= col;j++) {
            cin >> a[i][j];
        }

    // dp[i][j][5] : chua di lan nao
    dp[1][1][5] = 1;
    f[1][1] = 1;

    for(int i = 1;i <= row;i++)
        for(int j = 1;j <= col;j++) {

            if(a[i][j] == '#') continue;

            for(int nxt = 0;nxt < 5;nxt++) {
                f[i][j] = (f[i][j] % MOD + dp[i][j][nxt] % MOD) % MOD;
            }

            for(int nxt = 0;nxt < 5;nxt++) {
                int x = i + dx[nxt], y = j + dy[nxt];

                // cout << x << ' ' << y << '\n';

                if(a[x][y] != '#')
                    dp[x][y][nxt] = (dp[x][y][nxt] % MOD + 
                        f[i][j] % MOD - dp[i][j][nxt] % MOD + MOD) % MOD;
            }

        }
    
    cout << f[row][col];
    return 0;
}

// dp[i][j][k] : so cach di den [i,j] ma luc truoc da di tu o [i - dx[k],j - dy[k]] -> [i,j]
// -> khong duoc di theo huong k