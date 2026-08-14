#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
const int MM = 9;
int k,a[MM][MM],vis[MM][MM],choose[MM],used[MM][MM];
ll res = 0;
vector<pii> coord;

vector<int> knightX{-2,-1,1,2,2,1,-1,-2};
vector<int> knightY{1,2,2,1,-1,-2,-2,-1};
vector<pii> queen[MM][MM],rook[MM][MM],bishop[MM][MM],knight[MM][MM];

bool valid(int x,int y)
{
    return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

// queen rook bishop knight
void getqueen(int X,int Y)
{
    // queen

    for(int y = 1;y <= 8;y++) {
        queen[X][Y].push_back({X,y});
    }
    
    for(int x = 1;x <= 8;x++) {
        queen[X][Y].push_back({x,Y});
    }

    int u = X , v = Y; int mm = min(u,v);
    u = u - mm + 1, v = v - mm + 1;
    while(u <= 8 && v <= 8) {
        queen[X][Y].push_back({u,v});
        u++; v++;
    }
    u = X, v = Y;
    while(u - 1 >= 1 && v + 1 <= 8) {
        u--; v++;
    }
    while(u <= 8 && v >= 1) {
        queen[X][Y].push_back({u,v});
        u++; v--;
    }
}

void getrook(int X,int Y)
{
    // rook
    for(int y = 1;y <= 8;y++) {
        rook[X][Y].push_back({X,y});
    }
    
    for(int x = 1;x <= 8;x++) {
        rook[X][Y].push_back({x,Y});
    }
}

void getbishop(int X,int Y)
{
    int u = X , v = Y; int mm = min(u,v);
    u = u - mm + 1, v = v - mm + 1;
    while(u <= 8 && v <= 8) {
        bishop[X][Y].push_back({u,v});
        u++; v++;
    }
    u = X, v = Y;
    while(u - 1 >= 1 && v + 1 <= 8) {
        u--; v++;
    }
    while(u <= 8 && v >= 1) {
        bishop[X][Y].push_back({u,v});
        u++; v--;
    }
}

void getknight(int X,int Y)
{
    int x = X, y = Y;
    for(int i = 0;i < 8;i++) {
        int u = x + knightX[i], v = y + knightY[i];
        if(valid(u,v)) knight[X][Y].push_back({u,v});
    }
}

ll get(vector<pii> f[][MM],int id)
{
    ll res = 0;
    for(auto X:f[ coord[id].fi ][ coord[id].se ]) {
        int x = X.fi, y = X.se;
        if(used[x][y]) continue;
        res += a[x][y];
        used[x][y] = 1;
    }
    return res;
}

void Try(int id)
{
    if(id > 64) return;
    if(coord.size() == 4) {
        ll sum = get(queen,0) + get(rook,1) + get(bishop,2) + get(knight,3);
        res = max(res,sum);
        memset(used,0,sizeof(used));
        return;
    }
    int x = (id - 1) / 8 + 1;
    int y = (id - 1) % 8 + 1;

    if(!vis[x][y] && !a[x][y]) {
        for(int t = 1;t <= 4;t++) {
            if(choose[t]) continue;
    
            choose[t] = 1; vis[x][y] = 1;
            coord.push_back({x,y});
            Try(id+1);
            coord.pop_back();
            choose[t] = 0; vis[x][y] = 0;
            
        }
    }


    Try(id+1);
}   

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for(int i = 1;i <= k;i++) {
        int u,v,c;
        cin >> u >> v >> c;
        a[u][v] = c;
    }
    for(int i = 1;i <= 8;i++) 
        for(int j = 1;j <= 8;j++) {

            getqueen(i,j);
            getrook(i,j);
            getbishop(i,j);
            getknight(i,j);
        }
    Try(1);
    cout << res;
    return 0;
}
