#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1005;
vector<pair<int,int>> pos;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};
int visited[MM][MM],a[MM][MM];
int n,m,k;

void bfs(int x,int y)
{
    a[x][y] = 0;
    queue<pair<int,int>> q;
    q.push({x,y});
    pos.push_back({x,y});
    while(!q.empty()) {
        pair<int,int> coord = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X = coord.fi + dx[i];
            int Y = coord.se + dy[i];
            if(X >= 1 && X <= n && Y >= 1 && Y <= m) 
                if(a[X][Y] == 1) {
                    pos.push_back({X,Y});
                    q.push({X,Y});
                    a[X][Y] = 0;
                }
        }
    }
}

void update()
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) {
                bfs(i,j);
                return;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    update();
    // for(auto i:pos) cout << i.fi << ' ' << i.se << '\n';
    int h = pos.size();
    if(h < k) cout << "rotdoituyentinh";
    else {
        for(int i = h-1;i > h-k-1;i--) {
            cout << pos[i].fi << ' ' << pos[i].se << '\n';
        }
    }                                                                                             
    return 0;
}