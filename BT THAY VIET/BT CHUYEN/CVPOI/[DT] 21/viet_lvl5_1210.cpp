#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 2e3 + 7;
int num_row,num_col,a[MM][MM],ps[MM][MM];

int getsum(int x,int y,int u,int v)
{
    return ps[u][v] - ps[x - 1][v] - ps[u][y - 1] + ps[x - 1][y - 1];
}

namespace subtask2
{
    ll f[MM][MM];

    void update(int x,int y,int u,int v,int val)
    {
        f[x][y] += val;
        f[x][v + 1] -= val;
        f[u + 1][y] -= val;
        f[u + 1][v + 1] += val; 
    }

    void solve()
    {  
        for(int i = 1;i <= num_row;i++) {
            for(int j = i;j <= num_row;j++) {
                for(int x = 1, y = 1; y <= num_col;) {
                    if(getsum(i,y,j,y) != j - i + 1) {
                        x = ++y;
                        continue;
                    }
                    else {
                        while(y <= num_col && getsum(i,y,j,y) == j - i + 1) y++;
                    }

                    ll sum = 0;
                    for(;x < y;x++) {
                        sum += (y - x) - (y - x - 1);
                        update(i,x,j,y - 1,sum);
                    }
                }

            }
        }

        ll res = 0;
        for(int i = 1;i <= num_row;i++) {
            for(int j = 1;j <= num_col;j++) {
                f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
                res += f[i][j];
                // cout << f[i] wh[j] << ' ';
            }
            // cout << '\n';
        }
        cout << res;
    }
}

namespace subtask3
{
    void solve()
    {

    }
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
    cin >> num_row >> num_col;
    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) {
            char c; cin >> c;
            a[i][j] = (c == '.' ? 1 : 0);
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
        }
    
    subtask2::solve();
    return 0;
}