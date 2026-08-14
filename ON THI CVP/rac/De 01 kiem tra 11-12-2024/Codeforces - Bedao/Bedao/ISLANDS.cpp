#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll a[1005][1005];
ll m,n,cnt = 0;
void tracexy(ll x,ll y)
{
    if(a[x][y] == 0 || a[x][y] == -1) return;
    a[x][y] = -1;
    cnt++;
    if(x-1 >= 1 && x-1 <= m && y >= 1 && y <= n) tracexy(x-1,y);
    if(x+1 >= 1 && x+1 <= m && y >= 1 && y <= n) tracexy(x+1,y);
    if(x >= 1 && x <= m && y-1 >= 1 && y-1 <= n) tracexy(x,y-1);
    if(x >= 1 && x <= m && y+1 >= 1 && y+1 <= n) tracexy(x,y+1);
}

void backtrack(ll x,ll y)
{
    if(a[x][y] == 0 || a[x][y] == 1) return;
    a[x][y] = 1;
    if(x-1 >= 1 && x-1 <= m && y >= 1 && y <= n) backtrack(x-1,y);
    if(x+1 >= 1 && x+1 <= m && y >= 1 && y <= n) backtrack(x+1,y);
    if(x >= 1 && x <= m && y-1 >= 1 && y-1 <= n) backtrack(x,y-1);
    if(x >= 1 && x <= m && y+1 >= 1 && y+1 <= n) backtrack(x,y+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "ISLANDS"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }  
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
        }
    }
    ll ans = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j] == 0) {
                a[i][j] = 1;
                tracexy(i,j);
                ans = max(ans,cnt);
                cnt = 0;
                backtrack(i,j);
                a[i][j] = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
