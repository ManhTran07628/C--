#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6+7;
ll f[3001][3001];
ll tmp = 1e9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname "robot"
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll m,n;
    cin >> m >> n;
    for(int i = 1;i <= m;i++) {
        f[i][1] = 1;
    }
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) {
            f[j][i] = f[j-1][i-1] + f[j+1][i-1] + f[j][i];
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans = (ans + f[i][n]) % tmp; 
    }
    cout << ans;
    return 0;
}