#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+1;
ll w[N],v[N],f[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    #define taskname ""
    if(fopen(taskname ".inp","r"))
    {
        freopen(taskname ".inp","r",stdin);
        freopen(taskname ".out","w",stdout);
    }
    ll n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++) {
        cin >> w[i] >> v[i];
    }
    ll max1 = 0;
    for(int i = 1;i <= n;i++) { // trong luong
        for(int j = 1;j <= m;j++) { // khoi luong cai tui
            f[i][j] = f[i-1][j];
            if(j >= w[i]) {
                f[i][j] = max(f[i][j],f[i-1][j-w[i]] + v[i]);
                max1 = max(max1,f[i][j]);
            }
        }
    }
    cout << max1;
    return 0;
}
