#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
#define pii pair<int,int>
const int MM = 200 + 7;
int n,m,adj[MM][MM],d[MM][MM];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool check(int X,int Y)
{
    return (1 <= X && X <= n && 1 <= Y && Y <= m);
}

void solve()
{
    cin >> n >> m;
    queue<pii> q;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            d[i][j] = oo;
    for(int i = 1;i <= n;i++) {
        string s; cin >> s;
        for(int j = 0;j < m;j++) {
            adj[i][j+1] = s[j] - '0';
            if(adj[i][j+1]) {
                q.push({i,j+1});
                d[i][j+1] = 0;
            }
        }
    }

    while(!q.empty()) {
        int x = q.front().fi, y = q.front().se; q.pop();
        for(int i = 0;i < 4;i++) {
            int u = x + dx[i], v = y + dy[i];
            if(check(u,v) && d[u][v] > d[x][y] + 1) {
                d[u][v] = d[x][y] + 1;
                q.push({u,v});
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++)
            cout << d[i][j] << ' ';
        cout << '\n';
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
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}