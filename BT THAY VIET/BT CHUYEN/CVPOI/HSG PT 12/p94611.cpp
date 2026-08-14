#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,m;
int used[MM][MM];
vector<int> dx{-2,-1,1,2,2,1,-1,-2};
vector<int> dy{1,2,2,1,-1,-2,-2,-1};

void queenmove(int X,int Y)
{
    for(int i = 1;i <= n;i++) used[X][i]++;
    for(int i = 1;i <= n;i++) used[i][Y]++;
    for(int i = X,j = Y;i <= n && j <= n;i++,j++) used[i][j]++;
    for(int i = X,j = Y;i >= 1 && j <= n;i--,j++) used[i][j]++;
    for(int i = X,j = Y;i >= 1 && j >= 1;i--,j--) used[i][j]++;
    for(int i = X,j = Y;i <= n && j >= 1;i++,j--) used[i][j]++;   
}

void rookmove(int X,int Y)
{
    for(int i = 1;i <= n;i++) used[X][i]++;
    for(int i = 1;i <= n;i++) used[i][Y]++;
}

bool check(int X,int Y) {
    return (1 <= X && X <= n && 1 <= Y && Y <= n);
}

void knightmove(int X,int Y)
{
    used[X][Y] = 1;
    for(int i = 0;i < 8;i++) {
        if(check(dx[i] + X, dy[i] + Y))
            used[ dx[i] + X ][ dy[i] + Y ]++;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++) {
        char type;
        int x,y; cin >> type >> x >> y;
        if(type == 'Q') queenmove(x,y);
        else if(type == 'R') rookmove(x,y);
        if(type == 'N') knightmove(x,y);
    }
    int res = 0;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            if(used[i][j] > 0) res++;
    cout << res;
    return 0;
}