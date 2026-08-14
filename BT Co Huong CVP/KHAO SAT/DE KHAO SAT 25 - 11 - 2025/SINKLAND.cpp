#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e3 + 7;
const int MS = 1e6 + 7;
int n,m,w;
int a[MM][MM],dist[MM][MM],cnt[MS],comps = 0;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

struct Node
{
    int x,y,high;
};

struct cmp
{
    bool operator() (Node a,Node b)
    {
        return a.high > b.high;
    }
};

bool check(int x,int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> w;
    comps = n * m;
    priority_queue<Node,vector<Node>,cmp> q;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            dist[i][j] = oo;
            if(i == 1 || i == n || j == 1 || j == m) {
                q.push({i,j,a[i][j]});
                dist[i][j] = a[i][j];
            }
        }

    while(!q.empty()) {
        Node U = q.top(); q.pop();
        int x = U.x, y = U.y, high = U.high;
        if(high > dist[x][y]) continue;
        for(int i = 0;i < 4;i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            if(check(u,v) && dist[u][v] > max(a[u][v],dist[x][y])) {
                dist[u][v] = max(a[u][v],dist[x][y]);
                q.push({u,v,dist[u][v]});
            }
        }
            
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++)
            if(dist[i][j] != oo)
                cnt[ dist[i][j] ]++;
    }


    for(int i = 1;i <= w;i++) {
        cnt[i] += cnt[i-1];
        int res = n * m - cnt[i];
        cout << res << '\n';
    }
    


    return 0;
}