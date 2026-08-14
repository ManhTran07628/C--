#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
const int MM = 20;
char a[MM][MM];
int dist[MM][MM],w = -1,h = -1,startX,startY,distP[MM][MM],m = 0;
int dp[1 << 20][MM];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};
struct Node{int i,j,id;};
vector<Node> coord;

void readinput()
{
    coord.clear();
    m = 0;
    cin >> h >> w;
    for(int i = 1;i <= w;i++) {
        for(int j = 1;j <= h;j++) {
            cin >> a[i][j];
            if(a[i][j] == 'o') {
                startX = i,startY = j;
                coord.push_back({i,j,m++});
            }
        }
    }
    for(int i = 1;i <= w;i++) {
        for(int j = 1;j <= h;j++) {
            if(a[i][j] == '*') {
                coord.push_back({i,j,m++});
            }
        }
    }
}

bool bfs(int stx,int sty,int id)
{
    for(int i = 1;i <= w;i++) 
        for(int j = 1;j <= h;j++)
            dist[i][j] = oo;
    queue<pair<int,int>> q;
    q.push({stx,sty});
    dist[stx][sty] = 0;

    auto validcoord = [&] (int X,int Y) {
        return X >= 1 && Y >= 1 && X <= w && Y <= h;
    };

    while(!q.empty()) {
        int X1 = q.front().fi, Y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X2 = X1 + dx[i], Y2 = Y1 + dy[i];
            if(validcoord(X2,Y2) && a[X2][Y2] != 'x' && dist[X2][Y2] > dist[X1][Y1] + 1) {
                dist[X2][Y2] = dist[X1][Y1] + 1;
                q.push({X2,Y2});
            }
        }
    }
    for(auto v:coord) {
        distP[id][v.id] = dist[v.i][v.j];
        if(dist[v.i][v.j] == oo) return 0;
    }
    return 1;
}

int solve()
{
    for(auto v:coord) {
        if(!bfs(v.i,v.j,v.id)) return -1;
    }
    int n = coord.size();
    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) dp[mask][i] = oo;
    }
    for(int i = 0;i < n;i++) 
        dp[1 << i][i] = distP[0][i];

    for(int mask = 0;mask < (1 << n);mask++) {
        for(int i = 0;i < n;i++) {
            if(mask >> i & 1) {
                int p_mask = mask ^ (1 << i);
                for(int j = 0;j < n;j++) {
                    if(p_mask >> j & 1) 
                        dp[mask][i] = min(dp[mask][i],dp[p_mask][j] + distP[i][j]);
                }
            }
        }
    }
    int ans = oo;
    for(int i = 1;i < n;i++) {
        ans = min(ans,dp[(1 << n)-1][i]);
    }
    return ans;
}   

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(1)
    {
        readinput();
        if(!w && !h) break;
        cout << solve() << '\n';
    }
    return 0;   
}