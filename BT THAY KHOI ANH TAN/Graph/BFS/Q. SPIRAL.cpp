#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MM = 1005;
int a[MM][MM],xa,ya,xb,yb,visited[MM][MM];
int n,xc,yc,steps[MM][MM];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

void spiral(int n)
{
    int w = 0,st = 1;
    while(st <= n*n) {
        for(int j = w+1,i = w+1;j <= n-w;j++) {
            a[i][j] = st;
            st++;
        }
        for(int i = w+2,j = n-w;i <= n-w;i++) {
            a[i][j] = st;
            st++;
        }
        for(int i = n-w,j = n-w-1;j >= w+1;j--) {
            a[i][j] = st;
            st++;
        }
        for(int i = n-w-1,j = w+1;i > w+1;i--) {
            a[i][j] = st;
            st++;
        }
        w++;
    }
}

int bfs(int x,int y)
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            steps[i][j] = 1e18;
            visited[i][j] = 0;
        }
    }
    queue<pair<int,int>> q;
    visited[x][y] = 1;
    q.push({x,y});
    steps[x][y] = 0;
    while(!q.empty()) {
        pair<int,int> u = q.front();
        q.pop();
        for(int i = 0;i < 4;i++) {  
            int X = u.fi + dx[i];
            int Y = u.se + dy[i];
            if(X >= 1 && Y >= 1 && X <= n && Y <= n && !visited[X][Y]) {
                if(__gcd(a[u.fi][u.se],a[X][Y]) == 1) {
                    q.push({X,Y});
                    visited[X][Y] = 1;
                    steps[X][Y] = min(steps[u.fi][u.se]+1,steps[X][Y]);
                }
            }
        }
    }
    return steps[xb][yb];
}

void solve()
{
    cin >> n >> xc >> yc;
    spiral(n);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j] == xc) {
                xa = i; ya = j;
            }
            if(a[i][j] == yc) {
                xb = i; yb = j;
            }
        }
    }
    int ans = bfs(xa,ya);
    cout << (ans != 0 ? ans : -1) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}