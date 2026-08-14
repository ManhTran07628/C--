#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int MAXN = 1e6+7;
int a[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++) 
        for(int j = 1;j <= n;j++) 
            cin >> a[i][j];

    int ans = 0;
    for(int i = 1;i <= m;i++) 
    {
        for(int j = 1;j <= n;j++) 
        {
            if(a[i][j] > a[i-1][j] && a[i][j] > a[i][j-1] &&
               a[i][j] > a[i+1][j] && a[i][j] > a[i][j+1]
            ) ans++;
        }
    }
    cout << ans;
    return 0;
}