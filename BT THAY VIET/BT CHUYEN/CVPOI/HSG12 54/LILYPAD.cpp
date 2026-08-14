#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 30 + 7;
int rowNum,colNum,comps[MM][MM],cnt = 0,M = 0,stx = 0,sty = 0,enx = 0,eny = 0;
ll d[MM * MM],f[MM * MM];
pii a[MM][MM];
vector<int> sset[MM * MM], adj[MM * MM];
vector<pii> G;
vector<int> dx{-2,-1,1,2,2,1,-1,-2};
vector<int> dy{1,2,2,1,-1,-2,-2,-1};


bool valid(int x,int y)
{
    return (1 <= x && x <= rowNum && 1 <= y && y <= colNum);
}


void bfs(int x,int y,int C)
{
    queue<pii> q;
    q.push({x,y});
    while(!q.empty()) {
        pii U = q.front(); q.pop();
        int x = U.fi, y = U.se;
        comps[x][y] = C;
        for(int i = 0;i < 8;i++) {
            int u = x + dx[i], v = y + dy[i];
            if(valid(u,v) && a[u][v].fi == 1 && !comps[u][v]) {
                q.push({u,v});
            }
        }
    }
}

void process()
{
    for(auto E:G) {
        int u = E.fi, v = E.se;
        if(!comps[u][v]) {
            bfs(u,v,++cnt);
        }

        for(int i = 0;i < 8;i++) {
            int x = u + dx[i], y = v + dy[i];
            if(valid(x,y) && a[x][y].fi != 1 && a[x][y].fi != 2) {
                sset[ comps[u][v] ].push_back(a[x][y].se);
            }
        }
    }

    for(int i = 1;i <= rowNum;i++) 
        for(int j = 1;j <= colNum;j++) {

            if(a[i][j].fi == 1 || a[i][j].fi == 2) continue;

            for(int z = 0;z < 8;z++) {
                int x = i + dx[z], y = j + dy[z];
                if(valid(x,y) && a[x][y].fi != 1 && a[x][y].fi != 2) {
                    int u = a[i][j].se, v = a[x][y].se;
                    adj[u].push_back(v);
                    adj[v].push_back(u);
                }
            }
        }

    for(int i = 1;i <= cnt;i++) {
        sort(sset[i].begin(),sset[i].end());
        sset[i].erase(unique(sset[i].begin(),sset[i].end()),sset[i].end());

        for(auto u:sset[i]) 
            for(auto v:sset[i]) {
                if(u == v) continue;
                adj[u].push_back(v);
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
    cin >> rowNum >> colNum;

    for(int i = 1;i <= rowNum;i++)
        for(int j = 1;j <= colNum;j++) {
            cin >> a[i][j].fi;
            a[i][j].se = ++M;
            if(a[i][j].fi == 1) {
                G.push_back({i,j});
            }
            if(a[i][j].fi == 3) stx = i,sty = j;
            if(a[i][j].fi == 4) enx = i,eny = j;
        }

    process();
    
    queue<int> q;
    for(int i = 1;i <= M;i++) {
        d[i] = oo;
        sort(adj[i].begin(),adj[i].end());
        adj[i].erase(unique(adj[i].begin(),adj[i].end()),adj[i].end());
    }
    d[ a[stx][sty].se ] = 0;
    f[ a[stx][sty].se ] = 1;
    q.push(a[stx][sty].se);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v:adj[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                f[v] = f[u];
                q.push(v);
            }
            else if(d[v] == d[u] + 1) f[v] += f[u];
        }
    }
    int c = a[enx][eny].se;
    if(d[c] == oo) cout << -1;
    else {
        cout << d[c] - 1 << '\n' << f[c];
    }
    return 0;
}