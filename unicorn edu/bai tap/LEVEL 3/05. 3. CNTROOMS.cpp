#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,m;
char a[MM][MM];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool check(int X,int Y)
{
    return (1 <= X && X <= n && 1 <= Y && Y <= m);
}

void dfs(int X,int Y)
{
    a[X][Y] = '#';
    for(int i = 0;i < 4;i++) {
        int new_X = X + dx[i], new_Y = Y + dy[i];
        if(check(new_X,new_Y) && a[new_X][new_Y] == '.') {
            dfs(new_X,new_Y);
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }

    int res = 0;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == '.') {
                dfs(i,j);
                res++;
            }
        }

    cout << res;
    return 0;
}