#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define oo 1e18
const int MM = 500+7;
int n,k;
char a[MM][MM];
pair<int,int> cost[MM][MM]; // first - chiphi ban dau | second - chiphi sau
vector<int> dx{0,0,-1,1};
vector<int> dy{-1,1,0,0}; // L R U D

bool check(int x,int y) 
{
    if (x >= 1 && y >= 1 && x <= n && y <= n) return 1;
    return 0;
}

void bfs(int x,int y)
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cost[i][j] = {oo,oo};
        }
    }
    cost[x][y] = {0,0};
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()) {
        int X1 = q.front().fi, Y1 = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int X2 = X1 + dx[i], Y2 = Y1 + dy[i];
            if(check(X2,Y2) && (a[X2][Y2] == '.' || a[X2][Y2] == 'S')) {
                if(cost[X2][Y2].fi > cost[X1][Y1].fi+1) {
                    cost[X2][Y2].fi = cost[X1][Y1].fi+1;
                    q.push({X2,Y2});
                }
                if(cost[X2][Y2].se > cost[X1][Y1].se+1) {
                    cost[X2][Y2].se = cost[X1][Y1].se+1;
                    q.push({X2,Y2});
                }
            }
            int X3 = X2 + dx[i], Y3 = Y2 + dy[i];
            if(check(X2,Y2) && check(X3,Y3) && k == 1) {
                if(a[X2][Y2] == '*' && (a[X3][Y3] == 'S' || a[X3][Y3] == '.')) {
                    if(cost[X3][Y3].se > cost[X1][Y1].fi+1) {
                        cost[X3][Y3].se = cost[X1][Y1].fi+1;
                        q.push({X3,Y3});
                    }
                }
            }
        }   
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        cin >> n >> k;
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                cin >> a[i][j];
            }
        }
        bfs(1,1);
        if(k == 0) {
            if(cost[n][n].fi == oo) cout << -1; 
            else cout << cost[n][n].fi;
        }
        else {
            int ans = min(cost[n][n].fi,cost[n][n].se);
            cout << (ans != oo ? ans : -1);
        }
        cout << '\n';
    }
    return 0;
}