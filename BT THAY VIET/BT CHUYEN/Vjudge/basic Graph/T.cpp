#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
int n,m,a[MM][MM],dis[MM][MM],a1,b;
vector<int> dx{0,0,1,-1}; // R L D U
vector<int> dy{1,-1,0,0};

void bfs(int x,int y)
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dis[i][j] = oo;
        }
    }   
    dis[x][y] = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    a[x][y] = -1;
    while(!q.empty()) {
        int X1 = q.front().fi,Y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X2 = X1 + dx[i], Y2 = Y1 + dy[i];
            if(X2 >= 1 && Y2 >= 1 && X2 <= n && Y2 <= m) {
                if(a[X2][Y2] == 0 && dis[X2][Y2] > dis[X1][Y1] + 1) {
                    dis[X2][Y2] = dis[X1][Y1] + 1;
                    a[X2][Y2] = -1;
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
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    cin >> a1 >> b;
    bfs(a1,b);
    int ans = oo;
    for(int i = 1;i <= n;i++) {
        ans = min({ans,dis[i][1],dis[i][m]});
    }
    for(int i = 1;i <= m;i++) {
        ans = min({ans,dis[1][i],dis[n][i]});
    }
    cout << ans+1;
    return 0;
}