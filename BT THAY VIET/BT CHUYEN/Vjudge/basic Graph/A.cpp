#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 10+7;
int xA,yA,xB,yB,steps[MM][MM],vis[MM][MM];
vector<int> dx{-2,-1,1,2,2,1,-1,-2};
vector<int> dy{1,2,2,1,-1,-2,-2,-1};

void bfs(int x,int y)
{
    for(int i = 1;i <= 8;i++) {
        for(int j = 1;j <= 8;j++) {
            steps[i][j] = 1000;
        }
    }
    queue<pair<int,int>> q;
    q.push({x,y});
    vis[x][y] = 1;
    steps[x][y] = 0;
    while(!q.empty()) {
        int X1 = q.front().fi,Y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 8;i++) {
            int X2 = X1 + dx[i];
            int Y2 = Y1 + dy[i];
            if(X2 >= 1 && Y2 >= 1 && X2 <= 8 && Y2 <= 8 && !vis[X2][Y2]) {
                if(steps[X2][Y2] > steps[X1][Y1]) {
                    steps[X2][Y2] = steps[X1][Y1] + 1;
                    vis[X2][Y2] = 1;
                    q.push({X2,Y2});
                }
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> xA >> yA >> xB >> yB;
    bfs(xA,yA);
    cout << steps[xB][yB];
    return 0;
}