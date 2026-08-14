#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e18
#define pii pair<int,int>
#define BIT(x,y) ( ((x) >> (y)) & 1)
const int MM = 1e3+7;
const int MS = 1e6+7;
int n,m,c[MM][MM],q,comps = 0,vis[MM][MM],ans[MS];
pii par[MM][MM];
struct Node{int i,j,land;};
vector<Node> nodes;
struct QR{int Time,id;} qr[MS];
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

void make_sets()
{
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            par[i][j] = {i,j};
        }
    }
}

pii find_sets(pii a)
{
    if(a == par[a.fi][a.se]) return a;
    return par[a.fi][a.se] = find_sets(par[a.fi][a.se]);
}

void Unite(pii a,pii b)
{
    a = find_sets(a);
    b = find_sets(b);
    if(a == b) return;
    par[b.fi][b.se] = a;
    comps--;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> c[i][j];
            nodes.push_back({i,j,c[i][j]});
        }
    }
    make_sets();
    cin >> q;
    for(int i = 1;i <= q;i++) {
        cin >> qr[i].Time;
        qr[i].id = i;
    }
    sort(qr+1,qr+q+1, [] (QR a,QR b){
        return a.Time > b.Time;
    });
    sort(nodes.begin(),nodes.end(), [] (Node a,Node b){
        return a.land > b.land;
    });
    for(int i = 0,j = 1;j <= q;j++) {
        while(i < nodes.size() && nodes[i].land > qr[j].Time) {
            vis[ nodes[i].i ][ nodes[i].j ] = 1;
            for(int t = 0;t < 4;t++) {
                int x = nodes[i].i + dx[t];
                int y = nodes[i].j + dy[t];
                if(1 <= x && x <= n && 1 <= y && y <= m && vis[x][y]) {
                    pii a = {nodes[i].i,nodes[i].j};
                    pii b = {x,y};
                    Unite(a,b);
                }
            }
            i++;
            comps++;
        }
        ans[ qr[j].id ] = comps;
    }
    for(int i = 1;i <= q;i++) cout << ans[i] << '\n';

    return 0;   
}