#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
const int MM = 1500 + 7;
int n,m,k,a[MM][MM];

namespace subtask1
{
    void solve()
    {
        vector<int> vec;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++) {
                vec.push_back(a[i][j]);
            }
        sort(vec.begin(),vec.end(),greater<int>());
        cout << vec[0] + vec[1] + vec[2];
    }
}

namespace subtask2
{
    int dp[51][51][4],ps[51][51];

    int getsum(int x,int y,int u,int v)
    {
        return ps[u][v] - ps[x - 1][v] - ps[u][y - 1] + ps[x - 1][y - 1];
    }

    void solve()
    {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + a[i][j];
            }
        }

        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                for(int d = 1;d <= 3;d++) {
                    
                }
            }
        }
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
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    if(k == 1) subtask1::solve();
    return 0;
}