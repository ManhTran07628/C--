#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
char a[1005][1005];
int n,m,xb = 0,yb = 0,xa = 0,ya = 0;

vector<int> dx{0,0,-1,1}; // L R U D
vector<int> dy{-1,1,0,0};
pair<int,int> parent[1005][1005];
vector<char> direct{'D','R','U','L'};


void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    a[x][y] = '#';
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            int x1 = u.fi + dx[i];
            int y1 = u.se + dy[i];
            if(a[x1][y1] == 'B') {
                a[x1][y1] = '#';
                q.push({x1,y1});
                parent[x1][y1] = u;
                return;
            }
            if(x1 >= 1 && y1 >= 1 && x1 <= n && y1 <= m && a[x1][y1] == '.') {
                parent[x1][y1] = u;
                a[x1][y1] = '#';
                q.push({x1,y1});
            }
        }
    }
}

void Path()
{
    bfs(xa,ya);
    if(a[xb][yb] != '#') {
        cout << "NO";
    }
    else {
        cout << "YES" << '\n';
        vector<int> path;
        while(xb != xa || yb != ya) {
            for(int i = 0;i < 4;i++) {
                int u = xb + dx[i];
                int v = yb + dy[i];
                if(u == parent[xb][yb].fi && v == parent[xb][yb].se) {
                    xb += dx[i];
                    yb += dy[i];
                    path.push_back(i);
                    break;
                }
            }
        }
        cout << path.size() << '\n';
        reverse(path.begin(),path.end());
        for(auto i:path) {
            if(i == 0) cout << 'R';
            if(i == 1) cout << 'L';
            if(i == 2) cout << 'D';
            if(i == 3) cout << 'U';
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
                xa = i;ya = j;
            }
            if(a[i][j] == 'B') {
                xb = i;yb = j;
            }
        }
    }
    Path();
    return 0;
}