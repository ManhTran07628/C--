#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e9
#define pii pair<int,int>
const int MM = 1e3+7;
int n,m,x = 0,y = 0,dist[MM][MM],X = 0,Y = 0,sz = oo;
char a[MM][MM];
pii par[MM][MM];
vector<pii> ans;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

void tracepath(int u,int v,int x,int y)
{
    vector<pii> path;
    while(x != u || y != v) {
        path.push_back({x,y});
        pii cur = par[x][y];
        x = cur.fi, y = cur.se;
    }
    path.push_back({u,v});
    reverse(path.begin(),path.end());
    if(path.size() < sz) {
        sz = path.size();
        ans = path;
    }
}   

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            dist[i][j] = oo;
            if(a[i][j] == 'E') {
                x = i, y = j;
                X = i, Y = j;
            }
        }

    queue<pii> q;
    q.push({x,y});
    dist[x][y] = 0;
    while(!q.empty()) {
        x = q.front().fi, y = q.front().se;
        q.pop();
        for(int i = 0;i < 4;i++) {
            int u = x + dx[i];
            int v = y + dy[i];
            if(1 <= u && u <= n && 1 <= v && v <= m && 
            a[u][v] == 'O' && dist[u][v] > dist[x][y] + 1) {
                dist[u][v] = dist[x][y] + 1;
                par[u][v] = {x,y};
                q.push({u,v});
            }
        }
    }

    // cout << par[3][1].fi << ' ' << par[3][1].se << '\n';
    // cout << par[3][2].fi << ' ' << par[3][2].se << '\n';
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {

            if(i == 1 || j == 1 || i == n || j == m) 
                if(dist[i][j] != oo && a[i][j] != 'E') {
                    tracepath(X,Y,i,j);
                    // cout << i << ' ' << j << '\n';
                }
                
        }
    }
    // cout << X << ' ' << Y << '\n';
    if(!ans.size()) cout << -1;
    else {
        cout << ans.size() << '\n';
        for(auto U:ans) cout << U.fi << ' ' << U.se << '\n';
    }


    return 0;
}