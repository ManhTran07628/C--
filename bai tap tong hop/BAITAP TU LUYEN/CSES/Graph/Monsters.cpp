#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
int n,m,disA_x = 0,disA_y = 0,dis_ms[1001][1001],dis_A[1001][1001];
char a[1001][1001];
queue<pair<int,int>> q;
vector<int> dx{0,0,1,-1}; // R - L - D - U
vector<int> dy{1,-1,0,0};
pair<int,int> parent[1001][1001];
int valid_path = LLONG_MAX,end_x = 0,end_y = 0;

void bfs(queue<pair<int,int>> &q,int dis[1001][1001])
{
    while(!q.empty()) {
        int x1 = q.front().fi;
        int y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int x2 = x1 + dx[i];
            int y2 = y1 + dy[i];
            if(x2 >= 1 && y2 >= 1 && x2 <= n && y2 <= m && dis[x2][y2] == LLONG_MAX) {
                parent[x2][y2].fi = x1;
                parent[x2][y2].se = y1;
                dis[x2][y2] = min(dis[x2][y2],dis[x1][y1] + 1);
                q.push({x2,y2});
            }
        }
    }
}

void valid_exit(int i,int j)
{
    if(dis_ms[i][j] > dis_A[i][j]) {
        valid_path = dis_A[i][j];
        end_x = i;
        end_y = j;
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
            if(a[i][j] == '#') {
                dis_ms[i][j] = dis_A[i][j] = -1;
            }
            else dis_ms[i][j] = dis_A[i][j] = LLONG_MAX;
            if(a[i][j] == 'A') {
                disA_x = i;
                disA_y = j;
                dis_A[i][j] = 0;
            }
            if(a[i][j] == 'M') {
                dis_ms[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    bfs(q,dis_ms);
    q.push({disA_x,disA_y});
    bfs(q,dis_A);

    for(int i = 1;i <= n;i++) {
        valid_exit(i,1);
        valid_exit(i,m);
    }

    for(int i = 1;i <= m;i++) {
        valid_exit(1,i);
        valid_exit(n,i);
    }
    if(valid_path == LLONG_MAX) cout << "NO";
    else {
        cout << "YES" << '\n';
        vector<char> path;
        while(disA_x != end_x || disA_y != end_y) {
            for(int i = 0;i < 4;i++) {
                pair<int,int> idx {end_x+dx[i],end_y+dy[i]};
                if(parent[end_x][end_y] == idx) {
                    if(i == 0) path.push_back('L');
                    if(i == 1) path.push_back('R');
                    if(i == 2) path.push_back('U');
                    if(i == 3) path.push_back('D');
                    end_x += dx[i];
                    end_y += dy[i];
                    break;
                }
            }
        }
        reverse(path.begin(),path.end());
        cout << path.size() << '\n';
        for(auto x:path) cout << x;
    }
    return 0;
}