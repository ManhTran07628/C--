#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MM = 1e6+7;
int m,n,k;
pair<int,int> qr[MM];

void readinput()
{
    cin >> m >> n >> k;
    for(int i = 1;i <= k;i++) {
        cin >> qr[i].fi >> qr[i].se;
    }
}

namespace subtask12
{
    const int MS = 1000;
    int a[MS][MS];
    vector<pair<int,int>> dl;
    int getsum(int X1,int Y1,int X2,int Y2)
    {
        return a[X2][Y2] - a[X2][Y1-1] - a[X1-1][Y2] + a[X1-1][Y1-1];
    }

    bool check(int d)
    {
        for(int i = 1;i+d-1 <= m;i++) {
            for(int j = 1;j+d-1 <= n;j++) {
                int tmp = getsum(i,j,i+d-1,j+d-1);
                if(tmp == d*d) return 1;

            }
        }
        return 0;
    }

    void solve()
    {
        
        for(int q = 1;q <= k;q++) {

            for(int i = 1;i <= m;i++) {
                for(int j = 1;j <= n;j++) {
                    a[i][j] = 1;
                }
            }

            dl.push_back({qr[q].fi,qr[q].se});

            for(auto v:dl) a[v.fi][v.se] = 0;
            

            for(int i = 1;i <= m;i++) {
                for(int j = 1;j <= n;j++) {
                    a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
                }
            }
            int cnt = 0;
            for(int i = min(n,m);i >= 1;i--) 
                if(check(i)) {
                    cnt = max(cnt,i*i);
                    break;
                }
            cout << cnt << '\n';
        }
    }
}

namespace subtask3
{
    const int MS = 400+7;
    int cnt[MM];
    bool sq[MS][MS][MS];


    void Del(int x,int y,int l)
    {
        if(x < 1 || x > m || y < 1 || y > n) return;
        if(!sq[x][y][l]) return;
        else {
            sq[x][y][l] = 0;
            cnt[l]--;
        }
        Del(x-1,y-1,l+1);
        Del(x,y-1,l+1);
        Del(x-1,y,l+1);
        Del(x,y,l+1);
    }

    void solve()
    {
        int lim = min(n,m);
        for(int l = 1;l <= lim;l++) {
            for(int i = 1;i+l-1 <= m;i++) {
                for(int j = 1;j+l-1 <= n;j++) {
                    cnt[l]++;
                    sq[i][j][l] = 1;
                }
            }
        }

        for(int q = 1;q <= k;q++) {

            int x = qr[q].fi, y = qr[q].se;

            int ans = 0;
            Del(x,y,1);
            for(int i = lim;i >= 1;i--) {
                if(cnt[i] > 0) {
                    ans = i*i;
                    break;
                }
            }
            cout << ans << '\n';
        }

    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname "BONDING"
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    readinput();
    // subtask12::solve();
    subtask3::solve();
    return 0;
}
