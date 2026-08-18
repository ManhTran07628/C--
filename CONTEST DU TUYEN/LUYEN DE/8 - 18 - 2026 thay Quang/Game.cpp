#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 200 + 7;
int n,x_a,y_a,comps[MM][MM],timeDFS = 0,vis[MM][MM];
char a[MM][MM];

vector<pii> nodes;

vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool valid_coord(int x,int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= n);
}

void dfs(int x,int y)
{
    comps[x][y] = timeDFS;
    nodes.push_back({x,y});
    for(int i = 0;i < 4;i++) {
        int u = x + dx[i], v = y + dy[i];
        if(!comps[u][v] && valid_coord(u,v) && a[u][v] == '1') dfs(u,v);
    }
}

struct Node{int x,y,cur_step,dist_;};
struct cmp{bool operator() (Node a,Node b){return a.dist_ > b.dist_;}};

namespace sol
{
    int dist[MM][MM][401];

    void dijk()
    {
        dist[x_a][y_a][0] = 0;
        priority_queue<Node,vector<Node>,cmp> q;
        q.push({x_a,y_a,0,0});
        while(!q.empty()) {
            Node N = q.top(); q.pop();
            int x = N.x, y = N.y, step = N.cur_step;
            if(dist[x][y][step] > N.dist_) continue;

            for(auto id:nodes) {
                int u = id.fi, v = id.se;
                if(u == x_a && v == y_a) continue;
                int lim = abs(x_a - u) + abs(y_a - v);

                int dif = abs(u - x) + abs(v - y);


                if(comps[x][y] == comps[u][v]) {
                    if(dist[u][v][step] < N.dist_) {
                        dist[u][v][step] = N.dist_;
                        q.push({u,v,step,N.dist_});
                    }
                    continue;
                }

                if(step + dif <= lim && dist[u][v][step + dif] < N.dist_ + 1) {
                    dist[u][v][step + dif] = N.dist_ + 1;
                    q.push({u,v,step + dif,N.dist_ + 1});
                }
            }
        }
    }

    void solve()
    {
        dijk();
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {

                if((i == x_a && j == y_a) || a[i][j] == '0') {
                    cout << 0 << ' ';
                    continue;
                }

                int max_res = 1;
                for(int steps = 1;steps <= 200;steps++)
                    max_res = max(max_res,dist[i][j][steps]);

                cout << max_res << ' ';
            }
            cout << '\n';       
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
    cin >> n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++)
            cin >> a[i][j];

    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= n;j++) {
            if(!comps[i][j] && a[i][j] == '1') {
                ++timeDFS;
                dfs(i,j);
            }
        }
    cin >> x_a >> y_a;
    sol::solve();
    return 0;
}