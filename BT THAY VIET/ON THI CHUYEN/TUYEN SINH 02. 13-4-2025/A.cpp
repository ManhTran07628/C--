#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[101][101];
int n,m;
void bt(int x,int y)
{
    if(x > n || y > m || x < 1 || y < 1) return;
    if(!a[x][y]) return;
    a[x][y] = 0;
    bt(x+1,y);
    bt(x,y+1);
    bt(x-1,y);
    bt(x,y-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if(c == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) {
                ans++;
                bt(i,j);
            }
        }
    }
    cout << ans;
    return 0;
}