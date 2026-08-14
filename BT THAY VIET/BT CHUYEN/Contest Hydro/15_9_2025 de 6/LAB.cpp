#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo 1e5
const int MM = 100+7;
int n,m,q;
int Row[MM][MM],Col[MM][MM],dist[MM][MM][1 << 4];
int vis[MM][MM][1 << 4];
map<char,int> mp;
void readinput()
{
    cin >> n >> m;
    mp['P'] = 0; mp['C'] = 1, mp['Z'] = 2, mp['N'] = 3;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m-1;j++) {
            char c;
            cin >> c;
            Row[i][j] = mp[c];
        }
    }

    for(int i = 1;i <= n-1;i++) {
        for(int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            Col[i][j] = mp[c];
        }
    }
    cin >> q;

}

struct edge
{
    int x,y,cur_w,cur_mask;
};

struct cmp
{
    bool operator() (edge &a, edge &b)
    {
        return a.cur_w > b.cur_w;
    }
};

void dijkstra(int a,int b)
{
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            for(int mask = 0;mask < (1 << 4);mask++) {
                dist[i][j][mask] = oo;
            }
        }
    }
    priority_queue<edge,vector<edge>,cmp> q;
    q.push({a,b,0,0});
    dist[a][b][0] = 0;
    while(!q.empty()) {
        auto N = q.top(); q.pop();
        a = N.x, b = N.y;
        int cur_dist = N.cur_w, mask = N.cur_mask;
        if(vis[a][b][mask]) continue;
        vis[a][b][mask] = 1;
        if(b+1 <= m) {
            int dir = Row[a][b];
            int k = 0, new_mask = mask | (1 << dir);
            if(!(mask & (1 << dir))) k = 1;
            if(dist[a][b+1][new_mask] > cur_dist + k) {
                dist[a][b+1][new_mask] = cur_dist + k;
                q.push({a,b+1,dist[a][b+1][new_mask],new_mask});
            }
        }
        if(b-1 >= 1) {
            int dir = Row[a][b-1];
            int k = 0,new_mask = mask | (1 << dir);
            if(!(mask & (1 << dir))) k = 1;
            if(dist[a][b-1][new_mask] > cur_dist + k) {
                dist[a][b-1][new_mask] = cur_dist + k;
                q.push({a,b-1,dist[a][b-1][new_mask],new_mask});
            }
        }
        if(a+1 <= n) {
            int dir = Col[a][b];
            int k = 0,new_mask = mask | (1 << dir);
            if(!(mask & (1 << dir))) k = 1;
            if(dist[a+1][b][new_mask] > cur_dist + k) {
                dist[a+1][b][new_mask] = cur_dist + k;
                q.push({a+1,b,dist[a+1][b][new_mask],new_mask});
            }
        }
        if(a-1 >= 1) {
            int dir = Col[a-1][b];
            int k = 0,new_mask = mask | (1 << dir);
            if(!(mask & (1 << dir))) k = 1;
            if(dist[a-1][b][new_mask] > cur_dist + k) {
                dist[a-1][b][new_mask] = cur_dist + k;
                q.push({a-1,b,dist[a-1][b][new_mask],new_mask});
            }
        }



    }
}


void solve()
{
    while(q--) {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        dijkstra(a,b);
        int ans = oo;
        for(int mask = 1;mask < (1 << 4);mask++) 
            ans = min(ans,dist[c][d][mask]);
        cout << ans << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readinput();
    solve();
    return 0;
}