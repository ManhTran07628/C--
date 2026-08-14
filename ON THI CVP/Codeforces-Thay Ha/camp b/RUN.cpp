#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
int a[51][51],dx[4] = {0,0,1,-1},dy[4] = {1,-1,0,0},ch[51][51];
int r,c;
int markx[51][51],dd[51][51];
int inf = 1e5;
void loang1(int x,int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    markx[x][y] = 0;
    dd[x][y] = 1;
    while(!q.empty()) {
        int x = q.front().fi;
        int y = q.front().se;
        int d = min(markx[x][y])
        q.pop();
        for(int i = 0;i < 4;i++) {
            if(x+dx[i] > 0 && x+dx[i] <= r && y+dy[i] > 0 && y+dy[i] <= c
             && markx[x+dx[i]][y+dy[i]] == inf && ch[x+dx[i]][y+dy[i]] == 0
             && dd[x + dx[i]][y + dy[i]] == 0) {
                q.push({x + dx[i], y + dy[i]});
                markx[x + dx[i]][y + dy[i]] = d;
                dd[x + dx[i]][y + dy[i]] = 1;
             }
        }
    }
}




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> r >> c;
    int x1 = 0,y1 = 0,x2 = 0,y2 = 0,x3 = 0,y3 = 0;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            char x;
            cin >> x;
            if(x == '.') 
                a[i][j] = 0;
            if(x == 'D') {
                x1 = i;y1 = j;
                a[i][j] = 1;
            }
            if(x == '*') {
                x2 = i;y2 = j;
                a[i][j] = -1;
            }
            if(x == 'X') {
                a[i][j] = -1;
            }
            if(x == 'S') {
                x3 = i;y3 = j;
                a[i][j] = 0;
            }
        }
    }
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            ch[i][j] = a[i][j];
            markx[i][j] = inf;
        }
    }
    loang1(x1,y1);
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            cout << markx[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}