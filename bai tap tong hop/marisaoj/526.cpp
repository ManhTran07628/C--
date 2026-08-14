#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 500+7;
int n,m,ans = 0;
char a[MM][MM];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void bfs(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    a[x][y] = '#';
    int cnt = 1,ok = 1;
    while(!q.empty()) {
        int X1 = q.front().fi, Y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X2 = X1 + dx[i], Y2 = Y1 + dy[i];
            if(X2 >= 1 && Y2 >= 1 && X2 <= n && Y2 <= m) {
                if(a[X2][Y2] == '.') ok = 0;
                if(a[X2][Y2] == 'W') {
                    q.push({X2,Y2});
                    cnt++;
                    a[X2][Y2] = '#';
                }
            }
        }
    }
    if(ok) ans += cnt;
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
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == 'W') bfs(i,j);
        }
    }
    cout << ans;
    return 0;
}