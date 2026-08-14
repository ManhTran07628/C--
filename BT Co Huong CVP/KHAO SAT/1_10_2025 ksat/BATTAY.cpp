#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 2e5+7;
int n;
pair<int,int> coord[MM];
char c[MM];
void init()
{
    cin >> n;
    for(int i = 1;i <= n;i++) {
        cin >> coord[i].fi >> coord[i].se;
    }
    for(int i = 1;i <= n;i++) {
        cin >> c[i];
    }
}

namespace subtask1
{
    struct dl{int X; char dir;};
    vector<dl> adj[MM];
    void solve()
    {
        for(int i = 1;i <= n;i++) {
            adj[coord[i].se].push_back({coord[i].fi,c[i]});
        }
        for(int Y = 1;Y <= 2022;Y++) {
            sort(adj[Y].begin(),adj[Y].end(), [] (dl &a,dl &b){
                return a.X < b.X;
            });
        }
        ll ans = 0;
        for(int Y = 1;Y <= 2022;Y++) {
            for(int i = 0;i < adj[Y].size();i++) {
                int X1 = adj[Y][i].X;
                char dirX1 = adj[Y][i].dir;
                for(int j = i+1;j < adj[Y].size();j++) {
                    int X2 = adj[Y][j].X;
                    char dirX2 = adj[Y][j].dir;

                    if(dirX1 == 'R' && dirX2 == 'L') ans += 3;

                }

            }
        }
        
        cout << ans;
    }
}


namespace subtask3
{
    struct dl{int X; char dir;};
    vector<dl> adj[MM];
    int newc[MM];
    void solve()
    {

        vector<int> v;
        for(int i = 1;i <= n;i++) {
            v.push_back(coord[i].se);
        }
        sort(v.begin(),v.end(),[] (int &a,int &b){
            return a < b;
        });
        v.erase(unique(v.begin(),v.end()),v.end());

        for(int i = 1;i <= n;i++) {
            newc[i] = lower_bound(v.begin(),v.end(),coord[i].se)-v.begin();
            adj[newc[i]].push_back({coord[i].fi,c[i]});
        }
        int lim = v.size();


        for(int Y = 0;Y < lim;Y++) {
            sort(adj[Y].begin(),adj[Y].end(), [] (dl &a,dl &b){
                return a.X < b.X;
            });
        }

        ll ans = 0;
        for(int Y = 0;Y < lim;Y++) {
            int cntR = 0;
            for(int i = 0;i < adj[Y].size();i++) {
                int X1 = adj[Y][i].X;
                char dirX1 = adj[Y][i].dir;
                if(dirX1 == 'R') cntR++;
                else ans += cntR*3;
            }
        }

        cout << ans;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "BATTAY"
    if(fopen("taskname" ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    init();
    if(n <= 2000) subtask1::solve();
    else subtask3::solve();
    return 0;
}