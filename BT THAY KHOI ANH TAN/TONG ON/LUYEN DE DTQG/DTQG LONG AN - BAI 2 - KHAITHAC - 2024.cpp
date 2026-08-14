#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1e3 + 7;
int n,m,a[MM][MM],val[MM][MM];
ll comps_size = 0, comps_val = 0;
vector<int> dx{0,0,1,-1};
vector<int> dy{1,-1,0,0};

bool isvalid(int x,int y)
{
    return (1 <= x && x <= n && 1 <= y && y <= m);
}

void dfs(int x,int y)
{
    comps_val += val[x][y];
    comps_size++;
    a[x][y] = 0;
    for(int i = 0;i < 4;i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if(isvalid(u,v) && a[u][v]) {
            dfs(u,v);
        }
    }   
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #define taskname "KHAITHAC"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> a[i][j];
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++)
            cin >> val[i][j];
    
            
    
    ll maxval = 0,sz = 0;        
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) dfs(i,j);
            if(maxval < comps_val) {
                maxval = comps_val;
                sz = comps_size;
            }
            if(maxval == comps_val) 
                sz = min(sz,comps_size);
            
            comps_size = 0; comps_val = 0;
        }
    }

    cout << maxval << ' ' << sz;
            
    
    return 0;   
}