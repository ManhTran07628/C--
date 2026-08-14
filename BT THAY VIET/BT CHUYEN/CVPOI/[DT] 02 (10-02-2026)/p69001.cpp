#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int k,n;
struct QR{char type; int steps;} qr[MM];


void init()
{
    cin >> k >> n;
    for(int i = 1;i <= n;i++) {
        cin >> qr[i].type >> qr[i].steps;
    }
}

namespace subtask1
{
    int vis[(int) 1e3 + 7][(int) 1e3 + 7];
    int lim = 300;
    void solve()
    {
        int cur_X = lim, cur_Y = lim;
        int res = 1; vis[cur_X][cur_Y] = 1;
        for(int q = 1;q <= n;q++) {

            if(qr[q].type == 'E') {
                for(int i = 1;i <= qr[q].steps;i++) {
                    cur_X++;
                    if(!vis[cur_X][cur_Y]) res++;
                    vis[cur_X][cur_Y] = 1;
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                }
            }

            if(qr[q].type == 'W') {
               for(int i = 1;i <= qr[q].steps;i++) {
                    cur_X--;
                    if(!vis[cur_X][cur_Y]) res++;
                    vis[cur_X][cur_Y] = 1;
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                } 
            }
            
            if(qr[q].type == 'N') {
               for(int i = 1;i <= qr[q].steps;i++) {
                    cur_Y++;
                    if(!vis[cur_X][cur_Y]) res++;
                    vis[cur_X][cur_Y] = 1;
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                } 
            }

            if(qr[q].type == 'S') {
               for(int i = 1;i <= qr[q].steps;i++) {
                    cur_Y--;
                    if(!vis[cur_X][cur_Y]) res++;
                    vis[cur_X][cur_Y] = 1;
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                } 
            }

        }
        cout << res;
    }
}

const int MS2 = 4e3 + 7;
namespace subtask2
{
    int vis[MS2][MS2];
    int lim = 2000;

    bool checksub2()
    {
        bool ok = 1;
        for(int i = 1;i <= n;i++)
            if(qr[i].steps > 100) return 0;
        return (k <= 10);
    }

    void update(int x,int y,int u,int v)
    {
        for(int i = x;i < u;i++)
            for(int j = y;j < v;j++) {
                vis[i][j] = 1;
            }
    }

    void solve()
    {
        int x = lim, y = lim, u = lim + k, v = lim + k; 
        update(x,y,u,v);

        for(int q = 1;q <= n;q++) {

            if(qr[q].type == 'E') {
                for(int i = 1;i <= qr[q].steps;i++) {
                    x++, u++;
                    update(x,y,u,v);
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                }
            }

            if(qr[q].type == 'W') {
               for(int i = 1;i <= qr[q].steps;i++) {
                    x--; u--;
                    update(x,y,u,v);
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                } 
            }
            
            if(qr[q].type == 'N') {
               for(int i = 1;i <= qr[q].steps;i++) {
                    y++; v++;
                    update(x,y,u,v);
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                } 
            }

            if(qr[q].type == 'S') {
               for(int i = 1;i <= qr[q].steps;i++) {
                    y--; v--;
                    update(x,y,u,v);
                    // cout << cur_X - lim << ' ' << cur_Y - lim << '\n';
                } 
            }

        }

        int res = 0;
        for(int i = 0;i < MS2;i++)
            for(int j = 0;j < MS2;j++)  
                res += vis[i][j];
        cout << res;
    }
}

namespace subtask3
{
    map<pii,int> vis;

    void updateN(int x,int y,int u,int v)
    {
        for(int i = x;i < u;i++)
            vis[{i,v-1}] = 1;
    }

    void updateS(int x,int y,int u,int v)
    {
        for(int i = x;i < u;i++)
            vis[{i,y}] = 1;
    }

    void updateE(int x,int y,int u,int v)
    {
        for(int i = y;i < v;i++) 
            vis[{u-1,i}] = 1;
    }

    void updateW(int x,int y,int u,int v)
    {
        for(int i = y;i < v;i++)
            vis[{x,i}] = 1;
    }

    void solve()
    {
        int x = 0, y = 0, u = k, v = k; 

        for(int i = x;i < u;i++)
            for(int j = y;j < v;j++) {
                vis[{i,j}]= 1;
            }


        for(int q = 1;q <= n;q++) {

            if(qr[q].type == 'E') {
                for(int i = 1;i <= qr[q].steps;i++) {
                    x++, u++;
                    updateE(x,y,u,v);
                }
            }

            if(qr[q].type == 'W') {
                for(int i = 1;i <= qr[q].steps;i++) {
                    x--; u--;
                    updateW(x,y,u,v);
                }
            }
            
            if(qr[q].type == 'N') {
                for(int i = 1;i <= qr[q].steps;i++) {
                    y++; v++;
                    updateN(x,y,u,v);
                }
            }

            if(qr[q].type == 'S') {
                for(int i = 1;i <= qr[q].steps;i++) {
                    y--; v--;
                    updateS(x,y,u,v);
                }
            }

        }
        cout << vis.size();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    if(k <= 1 && n <= 10) subtask1::solve();
    else if(subtask2::checksub2) subtask2::solve();
    else subtask3::solve();
    return 0;
}