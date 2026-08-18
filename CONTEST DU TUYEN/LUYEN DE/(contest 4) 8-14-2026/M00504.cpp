#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e5 + 7;
int n;
struct Rec{int X1,Y1,X2,Y2;} rec[MM];

namespace subtask1
{
    int a[1001][1001];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            a[ rec[i].X1 ][ rec[i].Y1 ]++;
            a[ rec[i].X1 ][ rec[i].Y2 ]--;
            a[ rec[i].X2 ][ rec[i].Y1 ]--;
            a[ rec[i].X2 ][ rec[i].Y2 ]++;
        }

        int res = 0;
        for(int i = 0;i <= 1000;i++)
            for(int j = 0;j <= 1000;j++) {
                if(i > 0) a[i][j] += a[i - 1][j];
                if(j > 0) a[i][j] += a[i][j - 1];
                if(i > 0 && j > 0) a[i][j] -= a[i - 1][j - 1];
                if(a[i][j] >= 2) res++;
            }
        cout << res;
    }
}

namespace subtask3
{
    vector<pii> events;
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            events.push_back({rec[i].X1,1});
            events.push_back({rec[i].X2,-1});
        }

        sort(events.begin(),events.end());
        int last_pos = events[0].fi;
        int res = 0, sum = 0;
        for(auto id:events) {
            int cur_pos = id.fi, type = id.se;
            if(sum >= 2) res += cur_pos - last_pos;
            sum += type;
            last_pos = cur_pos;
        }
        cout << res;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r")) {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> rec[i].X1 >> rec[i].Y1 >> rec[i].X2 >> rec[i].Y2;
    }
    // subtask3::solve();
    if(n <= 2000) subtask1::solve();
    else subtask3::solve();
    return 0;
}