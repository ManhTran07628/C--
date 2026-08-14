#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[1005][1005],p[1005][1005],d[1005][1005];
map<int,int> lt;
int m,n;
int id = 0,t = 1;
void track(int x,int y)
{
    if(x < 1 || x > m || y < 1 || y > n) return;
    if(p[x][y] != 1) return;
    p[x][y] = 0;
    d[x][y] = t;
    id++;
    track(x+1,y);
    track(x-1,y);
    track(x,y+1);
    track(x,y-1);
}
void luugiatri(int x,int y)
{
    if(x < 1 || x > m || y < 1 || y > n) return;
    if(a[x][y] != 1) return;
    a[x][y] = id;
    luugiatri(x+1,y);
    luugiatri(x-1,y);
    luugiatri(x,y+1);
    luugiatri(x,y-1);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> a[i][j];
            p[i][j] = a[i][j];
        }
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j] == 1) 
            {
                track(i,j);
                luugiatri(i,j);
                id = 0;
                t++;
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            if(a[i][j] == 0) {
                ll sum = 0;
                if(lt[d[i-1][j]] != 1) {
                    sum += a[i-1][j];
                    lt[d[i-1][j]] = 1;
                }
                if(lt[d[i+1][j]] != 1) {
                    sum += a[i+1][j];
                    lt[d[i+1][j]] = 1;
                }
                if(lt[d[i][j-1]] != 1) {
                    sum += a[i][j-1];
                    lt[d[i][j-1]] = 1;
                }
                if(lt[d[i][j+1]] != 1) {
                    sum += a[i][j+1];
                    lt[d[i][j+1]] = 1;
                }
                lt[d[i-1][j]] = 0;
                lt[d[i+1][j]] = 0;
                lt[d[i][j+1]] = 0;
                lt[d[i][j-1]] = 0;
                ans = max(ans,sum+1);
            }
        }
    }
    if(ans == 0) ans = n*m;
    cout << ans;
    return 0;
}