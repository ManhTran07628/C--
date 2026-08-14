#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
int n,m,par[MM][MM],xa,ya,xb,yb;
char a[MM][MM],d[MM][MM];
vector<int> dx{0,0,1,-1}; // R L D U
vector<int> dy{1,-1,0,0};
vector<char> direct{'L','R','U','D'};
void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    a[x][y] = '#';
    while(!q.empty()) {
        pair<int,int> u = q.front(); q.pop();
        for(int i = 0;i < 4;i++) {
            pair<int,int> v = {u.fi+dx[i],u.se+dy[i]};
            if(v.fi >= 1 & v.se >= 1 && v.fi <= n && v.se <= m && a[v.fi][v.se] != '#') {
                a[v.fi][v.se] = '#';
                par[v.fi][v.se] = i;
                q.push({v.fi,v.se});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') {
                xa = i,ya = j;
            }
            if(a[i][j] == 'B') {
                xb = i,yb = j;
            }
            d[i][j] = a[i][j];
        }
    }
    bfs(xa,ya);
    if(a[xb][yb] != '#') cout << "NO";
    else {
        cout << "YES" << '\n';
        vector<char> path;
        while(xa != xb || ya != yb) {
            for(int i = 0;i < 4;i++) {
                if(par[xb][yb] == i) {
                    int j = 0;
                    if(i == 0) j = 1;
                    if(i == 1) j = 0;
                    if(i == 2) j = 3;
                    if(i == 3) j = 2;
                    xb += dx[j];
                    yb += dy[j];
                    path.push_back(direct[j]);
                    break;
                }
            }
        }
        reverse(path.begin(),path.end());
        cout << path.size() << '\n';
        for(auto i:path) cout << i;
    }    
    return 0;
}