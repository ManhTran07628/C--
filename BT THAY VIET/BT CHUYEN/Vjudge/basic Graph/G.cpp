#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
const int MM = 1e3+7;
int n,m,a[MM][MM],cnt = 0;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

void dfs(int x,int y)
{
    a[x][y] = 0;
    for(int i = 0;i < 4;i++) {
        int X = x + dx[i],Y = y + dy[i];
        if(X >= 1 && Y >= 1 && X <= n && Y <= m && a[X][Y]) {
            dfs(X,Y);
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
            char c;
            cin >> c;
            if(c == '#') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) {
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}