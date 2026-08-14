#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e3+5;
ll a[N][N],b[N][N];

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
        for(int j = 1;j <= m;j++) {
            cin >> a[i][j];
            b[i][j] = b[i][j-1] + a[i][j]; 
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            b[i][j] += b[i-1][j];
        }
    }
    ll q;
    cin >> q;
    while(q--) {
        ll x,y,u,v;
        cin >> x >> y >> u >> v;
        cout << b[u][v] - b[x-1][v] - b[u][y-1] + b[x-1][y-1] << '\n';
    }
    return 0;
}