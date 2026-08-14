#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int MAXN = 1e6+7;
char a[1005][1005];
vector<int> dx{0,0,-1,1}; // L R U D
vector<int> dy{-1,1,0,0};;
int n,m;
void dfs(int x,int y)
{
    a[x][y] = '#';
    for(int i = 0;i < 4;i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 1 && y1 >= 1 && x1 <= n && y1 <= m && a[x1][y1] == '.') {
            dfs(x1,y1);
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
    int cnt = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == '.') {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt;
    return 0;
}