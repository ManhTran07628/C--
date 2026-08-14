#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 500+7;
int g[MM][MM],h[MM][MM],visited[MM][MM];
vector<pair<int,int>> coord;
vector<int> dx{0,0,-1,1};
vector<int> dy{1,-1,0,0};
int n,m;

bool bfs(int x,int y,int dif)
{
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++)
            visited[i][j] = 0;
    queue<pair<int,int>> q;
    visited[x][y] = 1;
    q.push({x,y});
    while(!q.empty()) {
        int X1 = q.front().fi, Y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X2 = X1 + dx[i], Y2 = Y1 + dy[i];
            if(X2 >= 1 && Y2 >= 1 && X2 <= n && Y2 <= m) {
                int d = abs(g[X2][Y2]-g[X1][Y1]);
                if(!visited[X2][Y2] && d <= dif) {
                    visited[X2][Y2] = 1;
                    q.push({X2,Y2});
                }
            }
        }
    }
    for(auto [X,Y]: coord) 
        if(!visited[X][Y]) return 0;
    return 1;
}

void solve()
{
    int l = 0,r = 1e9,ans = 0;
    while(l <= r) {
        int mid = (l+r)/2;
        if(bfs(coord[0].fi,coord[0].se,mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) 
            cin >> g[i][j];

    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            cin >> h[i][j];
            if(h[i][j]) coord.push_back({i,j});
        }
    solve();
    return 0;
}