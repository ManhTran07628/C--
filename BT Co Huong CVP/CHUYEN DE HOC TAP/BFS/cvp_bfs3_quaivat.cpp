#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,m,monster[MM][MM],d[MM][MM];
pii par[MM][MM];
char a[MM][MM];
int posA = 0,posB = 0;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};
vector<char> dd{'R','L','D','U'};

bool check(int X,int Y)
{
    return (1 <= X && X <= n && 1 <= Y && Y <= m);
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
    cin >> n >> m;
    queue<pii> q1,q2;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            monster[i][j] = d[i][j] = oo;
        }

    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if(a[i][j] == 'M') {
                q1.push({i,j});
                monster[i][j] = 0;
            }
            if(a[i][j] == 'A') {
                posA = i, posB = j;
                q2.push({i,j});
                d[i][j] = 0;
                par[i][j] = {i,j};
            }


        }

    while(!q1.empty()) {
        int u = q1.front().fi, v = q1.front().se; q1.pop();
        for(int i = 0;i < 4;i++) {
            int x = u + dx[i], y = v + dy[i];
            if(check(x,y) && a[x][y] != '#' && monster[x][y] > monster[u][v] + 1) {
                monster[x][y] = monster[u][v] + 1;
                q1.push({x,y});
            }
        }
    }

    while(!q2.empty()) {
        int u = q2.front().fi, v = q2.front().se; q2.pop();
        for(int i = 0;i < 4;i++) {
            int x = u + dx[i], y = v + dy[i];
            if(check(x,y) && a[x][y] != '#' && d[x][y] > d[u][v] + 1) {
                d[x][y] = d[u][v] + 1;
                par[x][y] = {u,v};
                q2.push({x,y});
            }
        }
    }
    
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            if((i == 1 || i == n || j == 1 || j == m) && (a[i][j] == '.' || a[i][j] == 'A') && d[i][j] < monster[i][j]) {


                int cur_x = i, cur_y = j;
                vector<char> trace;
                while(cur_x != posA || cur_y != posB) {
                    int direct = 0;
                    int par_x = par[cur_x][cur_y].fi, par_y = par[cur_x][cur_y].se;
                    for(int i = 0;i < 4;i++) {
                        int nxt_x = cur_x + dx[i], nxt_y = cur_y + dy[i];
                        if(nxt_x == par_x && nxt_y == par_y) {
                            if(i == 0) {trace.push_back('L');break;}
                            if(i == 1) {trace.push_back('R');break;}
                            if(i == 2) {trace.push_back('U');break;}
                            if(i == 3) {trace.push_back('D');break;}
                        }
                    }

                    cur_x = par_x, cur_y = par_y;
                }

                reverse(trace.begin(),trace.end());
                cout << "YES" << '\n' << trace.size() << '\n';
                for(auto x:trace) cout << x;
                return 0;
            }
        }
    cout << "NO";
    return 0;
}