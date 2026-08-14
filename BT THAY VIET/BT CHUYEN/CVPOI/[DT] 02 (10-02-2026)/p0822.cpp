#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 5e3 + 7;
int n,m,a[MM][MM];
struct Coord{int x,y,v;};
vector<Coord> cd;

void init()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        int x,y,v; cin >> x >> y >> v;
        cd.push_back({x,y,v});
        a[x][y] = v;
    }
}

namespace subtask13
{
    void solve()
    {
        int limX = 0,limY = 0;
        for(auto X:cd) {
            int x = X.x, y = X.y, v = X.v;
            limX = max(limX,x);
            limY = max(limY,y);
        }
        double edge = m / 2.0;
        int res = 0;
        for(double x = 0.0;x + edge <= (double) limX + 0.1;x += 0.1) {
            for(double y = 0.0;y + edge <= (double) limY + 0.1;y += 0.1) {
                int cur_res = 0;
                double Upper_square = y + edge;
                double Right_square = x + edge;
                double left_square = x - edge;
                double Lower_square = y - edge;

                for(auto X:cd) {
                    double x = X.x, y = X.y; int v = X.v;
                    if(left_square < x && x < Right_square && Lower_square < y && y <= Upper_square) 
                        cur_res += v;
                }

                res = max(res,cur_res);
            }
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    subtask13::solve();

    return 0;
}