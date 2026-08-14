#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6+7;
ll a[2001][2001];
ll cnt = 0;
ll n,m,x,y;
void doduong(ll x,ll y)
{
    if(x < 1 || x > n || y < 1 || y > m) return;
    if(a[x][y] != 0) return;
    if(x)
    cnt++;
    a[x][y]=1;
    doduong(x+1,y);
    doduong(x,y+1);
    doduong(x-1,y);
    doduong(x,y-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "OCSEN"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    cin >> n >> m >> x >> y;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
        }
    }
    doduong(x,y);
    if(cnt == 0) cout << -1;
    else cout << cnt;
    return 0;
}
