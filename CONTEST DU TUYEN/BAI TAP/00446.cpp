#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e9
const int MM = 6400 + 7;
int num_row,num_col,nums[MM][MM],cntm = 0,vis[MM],max_matching = 0;
int matchL[MM];
char a[MM][MM];

vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool isvalid(int x,int y)
{
    for(int i = 0;i < 4;i++) {
        int u = x + dx[i], v = y + dy[i];
        if(a[u][v] == '2') return 0;
    }
    return a[x][y] == '0';
}

vector<int> adj[MM],subsetL;
void dfs(int u,int par,int color)
{
    if(vis[u]) return;
    vis[u] = 1;
    if(color == 0) subsetL.push_back(u);
    for(auto v:adj[u]) {
        if(v == par || vis[v]) continue;
        dfs(v,u,color ^ 1);
    }
}

bool kuhn(int u)
{
    for(auto v:adj[u]) {
        if(vis[v]) continue;
        vis[v] = 1;

        if(!matchL[v] || kuhn(matchL[v])) {
            matchL[v] = u;
            return 1;
        }
    }
    return 0;
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
    cin >> num_row >> num_col;
    int cnt2 = 0;
    for(int i = 0;i <= num_row + 1;i++)
        for(int j = 0;j <= num_col + 1;j++) 
            a[i][j] = '1';

    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) {
            cin >> a[i][j];
            nums[i][j] = ++cntm;
            if(a[i][j] == '2') cnt2++;
        }

    vector<int> vec;
    for(int i = 1;i <= num_row;i++)
        for(int j = 1;j <= num_col;j++) 
            if(isvalid(i,j)) {
                vec.push_back( nums[i][j] );
                for(int k = 0;k < 4;k++) {
                    int u = i + dx[k], v = j + dy[k];
                    if(isvalid(u,v) && 1 <= i && i <= num_row &&
                        1 <= j && j <= num_col) {
                        adj[ nums[i][j] ].push_back( nums[u][v] );
                        adj[ nums[u][v] ].push_back( nums[i][j] );
                    }
                }
            }

    for(auto u:vec) {
        dfs(u,0,0); //cout << u << '\n';
    }

    for(auto u:subsetL) {
        // cout << u << '\n';
        fill(vis+1,vis+cntm+1,0);
        if(kuhn(u)) max_matching++;
    }

    cout << vec.size() - max_matching + cnt2;
    
    return 0;
}
