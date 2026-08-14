#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int num_row,num_col,k,a[MM][MM];
struct Trace{int u,v,dc;} par[MM][MM][6];
ll d[MM][MM][6],res = oo;
vector<pii> trace;
struct Node{int x,y,discount;ll dist_;};
struct cmp{bool operator() (Node a,Node b) {return a.dist_ > b.dist_;}};

vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool isvalid(int x,int y)
{
    return (1 <= x && x <= num_row && 1 <= y && y <= num_col);
}

void dijk(int x)
{
    priority_queue<Node,vector<Node>,cmp> q;

    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++)
            for(int s = 0;s <= k;s++) d[i][j][s] = oo;

    for(int i = 1;i <= num_row;i++) {
        int start_discount = (a[i][1] == 0) ? k : 0;
        d[i][1][start_discount] = a[i][1];
        q.push({i,1,start_discount,a[i][1]});
        par[i][1][start_discount] = {-1,-1,-1}; 
    }

    ll cur_res = oo, last_x = -1, last_dc = -1;
    
    while(!q.empty()) {
        Node N = q.top(); q.pop();
        int x = N.x, y = N.y, discount = N.discount;
        if(y == num_col) {
            if(d[x][y][discount] < cur_res) {
                cur_res = d[x][y][discount];
                last_x = x;
                last_dc = discount;
            }
        }
        if(N.dist_ > d[x][y][discount]) continue;
        for(int i = 0;i < 4;i++) {
            int u = x + dx[i], v = y + dy[i];

            if(!isvalid(u,v)) continue;

            ll new_discount,new_dist;// = (discount > 0 ? 0 : a[u][v]);

            if(a[u][v] == 0) {
                new_discount = k;
                new_dist = 0;
            } 
            else {
                new_discount = max(0, discount - 1);
                new_dist = (discount > 0 ? 0 : a[u][v]);
            }

            if(d[u][v][new_discount] > d[x][y][discount] + new_dist) {
                d[u][v][new_discount] = d[x][y][discount] + new_dist;
                q.push({u,v,new_discount,d[u][v][new_discount]});
                par[u][v][new_discount] = {x,y,discount};
            }
        }
    }

    if(cur_res < res) {
        int cur_row = last_x, cur_col = num_col;
        vector<pii> state;
        while(cur_col != 1) {
            state.push_back({cur_row,cur_col});
            Trace f = par[cur_row][cur_col][last_dc];
            cur_row = f.u, cur_col = f.v;
            last_dc = f.dc;
        }
        state.push_back({cur_row,cur_col});
        res = cur_res;
        trace = state;
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
    cin >> num_row >> num_col >> k;
    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) {
            cin >> a[i][j];
        }

    dijk(36);

    cout << res << '\n';
    reverse(trace.begin(),trace.end());
    for(auto E:trace) cout << E.fi << ' ' << E.se << '\n';

    return 0;
}