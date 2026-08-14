#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define oo (ll) 1e18
#define pii pair<int,int>
const int MM = 1000 + 7;
int n,m,vis[MM][MM];
char a[MM][MM];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++)
            cin >> a[i][j];
    
    int cnt = 0;
    for(int i = 1;i <= n;i++) 
        for(int j = 1;j <= m;j++) {
            if(vis[i][j]) continue;
            if(a[i][j] == '#') {
                vis[i][j] = 1;
                if(a[i+1][j] == '#') vis[i+1][j] = 1;
                if(a[i][j+1] == '#') vis[i][j+1] = 1;
                if(a[i-1][j] == '#') vis[i-1][j] = 1;
                if(a[i][j-1] == '#') vis[i][j-1] = 1;
                cnt++;
            }
        }
    cout << cnt;
    return 0;
}